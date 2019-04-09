#ifndef __WEBSERVER_HPP__
#define __WEBSERVER_HPP__

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <thread>

using namespace std;

class WebServer{
    public:
    WebServer();
    ~WebServer();

    int ServerInit(u_short port);
    int ServerError(string str);
    int ServerAccept();
    int ServerClose();
    int ServerRequest(int cli_fd);
    int get_line(int cli_fd,char * buf,int size);
    int ServerCatHttpPage(int cli_fd,char *path);
    int Page_Headers(int cli_fd,char *type);
    int Page_Cat(int cli_fd,FILE * fp);

    int Page_200(int cli_fd);
    int Page_501(int cli_fd);
    int Page_404(int cli_fd);

    private:
    int httpd;
};

#endif