#include<stdio.h>
#include<netdb.h>
#include<unistd.h>

int main(int argc, char** argv){
    int servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(servSock < 0){
        fprintf(stderr, "Socket Failed\n");
    }
    struct sockaddr_in echoServAddr;
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_port = htons(8999);
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(servSock,(struct sockaddr*)&echoServAddr,sizeof(echoServAddr)) < 0){
        fprintf(stderr, "Bind failed\n");
    }

    if(listen(servSock, 5) < 0){
        fprintf(stderr, "Listen failed\n");
    }
    struct sockaddr_in echoClntAddr;
    echoClntAddr.sin_family = AF_INET;
    echoClntAddr.sin_port = htons(9999);
    echoClntAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    while(1 == 1){
        int clntLen = sizeof(echoClntAddr);
        int clientSock = accept(servSock,(struct sockaddr*)&echoClntAddr,&clntLen);
        
        if(clientSock < 0){
            fprintf(stderr, "Accept failed\n");
        } else {
            char* val = "kaines";
            int echoStringLen = strlen(val);

            if(send(clientSock, val, echoStringLen, 0) != echoStringLen){
                fprintf(stderr, "Send unsucessfull\n");
            }
        }
    }
    close(servSock);

}
