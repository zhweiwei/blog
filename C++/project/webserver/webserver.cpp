#include "webserver.h"
using namespace std;

int WebServer::ServerRequest(int cli_fd)
{
    char buf[1024];
    int size=1024;
    int i,j;
    char method[255];//用于保存请求方式
    char url[512];
    char path[1024];
    struct stat st;
    int cgi;
    memset(buf,0,sizeof(buf));
    cgi=0;
    //获取第一行请求信息 一般格式为: GET / HTTP/1.1
    //                               POST / HTTP/1.1
    size=get_line(cli_fd,buf,sizeof(buf));
    cout<<"\t\t"<<buf<<endl;
    i=0,j=0;
    //截取第一个单词
    while(!isspace(buf[j]) && (i<sizeof(method)-1))
    {
        method[i]=buf[j];
        i++;j++;
    }
    method[i]='\0';
    //取第一个与第二个单词之间的空格
    while(isspace(buf[j]) && (j<sizeof(buf)))
        j++;
    //截取第二个单词
    i=0;
    while(!isspace(buf[j]) && (i<sizeof(url)-1) && (j<sizeof(buf)))
    {
        url[i]=buf[j];
        i++;j++;
    }
    url[i]='\0';

    if(strcasecmp(method,"GET") && strcasecmp(method,"POST"))
    {
        Page_501(cli_fd);
        return -1;
    }

    if(strcasecmp(method,"GET")==0)
    {
        cout<<"此次请求的方式是GET方法"<<endl;
    }
    else if(strcasecmp(method,"POST")==0)
    {
        cout<<"此次请求的方式是POST方法"<<endl;
    }
    cout<<"此次请求的地址为:"<<url<<endl;

    sprintf(path,"www%s",url);//这个是web服务器的主目录，这个以后可以处理成读取配置文件，这里就先写固定的www目录
    if(path[strlen(path)-1]=='/')
        strcat(path,"index.html");//同上

    //根据文件名，获取该文件的文件信息。如果为-1，表示获取该文件失败
    if(stat(path,&st)==-1)
    {
        while((size>0) && strcmp("\n",buf))//去除掉多余的请求头信息
            size=get_line(cli_fd,buf,sizeof(buf));
        Page_404(cli_fd);
    }
    else
    {
        if((st.st_mode & S_IFMT)== S_IFDIR)//判断url地址，如果是个目录，那么就访问该目录的index.html
        {
            strcat(path,"/index.html");
        }
        // if((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) || (st.st_mode & S_IXOTH))//判断该url地址所对应的文件是否是可执行，并且是否有权限
        // {
        //     cgi=1;//是一个cgi程序
        // }
        if(cgi==0)//如果cgi为0，那么就表示该url所对应的文件不是cgi程序，而是一个简单的静态页面
        {
            ServerCatHttpPage(cli_fd,path);
        }
    }

    if(fork()==0)
    {
        //处理阶段
        //execl("/bin/ls","ls","/home/myuser/",NULL);
        //Page_200(cli_fd);
    }
    close(cli_fd);
    return 0;
}

int WebServer::ServerAccept(){
    struct sockaddr_in cli_sin;
    socklen_t cli_len = sizeof(cli_sin);
    int cli_fd;

    cli_fd = accept(httpd,(struct sockaddr *)&cli_sin,&cli_len);
    if(cli_fd == -1)
    ServerError("Fail to accept");
    cout<<"连接进来的ip："<<inet_ntoa(cli_sin.sin_addr)<<" : "<<ntohs(cli_sin.sin_port)<<endl;
    return cli_fd;
}

int WebServer::ServerInit(u_short port){
    struct sockaddr_in sin;
    int on;
    httpd = socket(AF_INET,SOCK_STREAM,0);
    if(httpd == -1){
        ServerError("Fail to Socket");
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    bzero(&(sin.sin_zero),8);
    setsockopt(httpd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
    if(::bind(httpd,(struct sockaddr*)&sin,sizeof(struct sockaddr)) == -1)
    ServerError("Fail to bind");

    if(port == 0){
        socklen_t len = sizeof(sin);
        if(getsockname(httpd,(struct sockaddr *)&sin,&len) == -1)
        ServerError("Fail to getsockanme");
        port = ntohs(sin.sin_port);
    }

    if(listen(httpd,100) < 0)
    ServerError("fail to listen");

    return port;
}

int WebServer::get_line(int cli_fd,char * buf,int size)
{
    int i=0;
    char c='\0';
    int n;
    while((i<size-1)&&(c!='\n'))
    {
        n=recv(cli_fd,&c,1,0);
        if(n>0)
        {
            if(c=='\r')
            {
                n=recv(cli_fd,&c,1,MSG_PEEK);
                if((n>0)&&(c=='\n'))
                    recv(cli_fd,&c,1,0);
                else
                    c='\n';
            }
            buf[i]=c;
            i++;
        }
        else
            c='\n';
    }
    buf[i]='\0';
    return i;
}

int WebServer::ServerError(string str){
    perror(str.c_str());
    exit(-1);
}

int WebServer::ServerClose(){
    close(httpd);
    return 0;
}


 
int WebServer::ServerCatHttpPage(int cli_fd,char *path,int filesize)
{
    FILE * resource=NULL;
    int size=1;
    char buf[1024];
    char type[32];
    char * p =type;
    buf[0]=1;buf[1]=0;
    while((size>0) && strcmp("\n",buf))//去除掉多余的请求头信息
        size=get_line(cli_fd,buf,sizeof(buf));

    //判断文件类型
    int len=strlen(path);
    cout<<path<<":"<<filesize<<endl;
    if(path[len-4]=='h'&&path[len-3]=='t'&&path[len-2]=='m'&&path[len-1]=='l')
    {
        strcpy(type,"text/html");
    }
    else if(path[len-4]=='.'&&path[len-3]=='i'&&path[len-2]=='c'&&path[len-1]=='o')
    {
        strcpy(type,"image/x-icon");
    }
    else if(path[len-4]=='.'&&path[len-3]=='j'&&path[len-2]=='p'&&path[len-1]=='g')
    {
        strcpy(type,"image/jpeg");
    }
    else
    {
        strcpy(type,"text/html");
    }
    cout<<"请求资源的类型:"<<type<<endl;

    resource=fopen(path,"r");//根据GET后面的文件吗，将文件打开
    if(resource==NULL)//打开文件失败
    {
        Page_404(cli_fd);
    }
    else
    {
        Page_Headers(cli_fd,p,filesize);
        Page_Cat(cli_fd,resource);
    }
    fclose(resource);
    return 0;
}

int WebServer::Page_Headers(int cli_fd,char * type)
{
    char buf[1024];
    strcpy(buf,"HTTP/1.1 200 OK\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "Server:wunaozai.cnblogs.com\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: %s\r\n",type);
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    return 0;
}
int WebServer::Page_Cat(int cli_fd,FILE * fp)
{
    char buf[1024];

    fgets(buf,sizeof(buf),fp);
    while(!feof(fp))
    {
        send(cli_fd,buf,strlen(buf),0);
        fgets(buf,sizeof(buf),fp);
    }
    return 0;
}


int WebServer::Page_200(int cli_fd){
    char buf[1024];
    sprintf(buf, "HTTP/1.1 200 OK\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "Server:zhuweiwei.com\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "<HTML><HEAD><TITLE>Hello World\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "</TITLE></HEAD>\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "<BODY><h1>Hello World</h1>\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "</BODY></HTML>\r\n");
    send(cli_fd, buf, strlen(buf), 0);
}

int WebServer::Page_501(int cli_fd){
        char buf[1024];
    sprintf(buf, "HTTP/1.1 501 Method Not Implemented\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "Server:zhuweiwei.com");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "<HTML><HEAD><TITLE>Method Not Implemented\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "</TITLE></HEAD>\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "<BODY><P>HTTP request method not supported.\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "</BODY></HTML>\r\n");
    send(cli_fd, buf, strlen(buf), 0);
}

int WebServer::Page_404(int cli_fd){
        char buf[1024];
    sprintf(buf, "HTTP/1.1 404 Method Not Implemented\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "Server:zhuweiwei.com");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html;charset=utf-8\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "<HTML><HEAD><TITLE>PAGE NOT FOUND\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "</TITLE></HEAD>\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "<BODY><P>The server could not fulfill.\r\n");
    send(cli_fd, buf, strlen(buf), 0);
    sprintf(buf, "</BODY></HTML>\r\n");
    send(cli_fd, buf, strlen(buf), 0);
}


 WebServer::WebServer(){}

 WebServer::~WebServer(){}