/*
Author - k4m1k4z13r
Copyright: Copy what you can
*/
//Compile - gcc ./ascii-client.c -o client
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>

#define ERROR -1  //define error status integer as -1
#define BUFFER 256 //define the size of the buffer

void fatal(char message[])//handle fatal errors
{
printf("fatal error while %s \n", message);
exit(-1);
}

void usage()//display usage message and exit
{
printf("usage: ./client [IP address of remote host] [port-number]\n");
exit(1);
}

int main(int *argc,char *argv[])
{
if(argc<2) usage();
int sockfd;
char message[BUFFER];
struct sockaddr_in remote_host;
remote_host.sin_family=AF_INET;
remote_host.sin_port=htons(atoi(argv[2]));//provide port number
remote_host.sin_addr.s_addr=inet_addr(argv[1]);//provide IP of remote host
memset(&(remote_host.sin_zero), '\0', 8); // Zero the rest of the struct.



sockfd=socket(AF_INET, SOCK_STREAM, 0);//create a tcp socket and fetch the file descriptor
	if(sockfd==-1) fatal("creating socket");//error handling

if(connect(sockfd, (struct sockaddr *)&remote_host,  sizeof(struct sockaddr_in))==ERROR) fatal("connecting to remote host");//connect to remote host and handle fatal errors

printf("Got the connection. Go ahead and enter your message to send to the remote host\n");


while(1)//a loop to keep accepting messages
{
fgets(message, BUFFER, stdin);
send(sockfd, message, strlen(message), 0);
}
strcpy(message, "Closing the connection\n");
close(sockfd);
}
