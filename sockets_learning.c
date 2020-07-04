#include<stdio.h>
#include<netdb.h>

int main(int argc, char** argv){

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        printf("socket not created\n");
    } else {
        printf("socket created!\n");
        printf("socket id: %d\n",sock);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = 8888;
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sock,(struct sockaddr*)&server,sizeof(server)) == -1){
        printf("bind unsucessfull\n");
    } else {
        printf("bind complete\n");
    }
    if(listen(sock,5)==-1){
        printf("not listening!\n");
    } else {
        printf("listening in socket id: %d\n",sock);
    }
    int status;
    status = close(sock);
    printf("socket freed!\n");
    return 0;
}
