#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

#define echoServIP "localhost"
#define echoServPort 9999

int main(int argc, char** argv){
    int clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(clientSock < 0){
        fprintf(stderr, "Socket failed\n");
    }
    struct sockaddr_in echoServAddr;
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = htons(echoServIP);
    echoServAddr.sin_port = htonl(echoServPort);

    if(connect(clientSock, (struct sockaddr*)&echoServAddr, sizeof(echoServAddr)) < 0){
        fprintf(stderr, "Connect failed\n");
    }
    char buff[100];
    int recvMsgSize;
    while((recvMsgSize = recv(clientSock,buff,100,0)) > 0){
        if((recvMsgSize = recv(clientSock,buff,100,0) < 0)){
            fprintf(stderr, "Recv failed\n");
        }
        else{
            fprintf(stdout, "echo from server %s\n",buff);
        }
    }
    close(clientSock);

}
