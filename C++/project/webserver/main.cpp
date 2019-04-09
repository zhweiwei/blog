#include "webserver.h"

int main(int argc,char **argv){
    WebServer ws;
    ws.ServerInit(8080);
    pid_t pid;
    int cli_fd;

    while(1){
        cli_fd = ws.ServerAccept();
        ws.ServerRequest(cli_fd);

    }

    ws.ServerClose();

    return 0;
}