/*
Author - k4m1k4z13r
Copyright: Copy what you can
*/
//Compile - gcc ./ascii-server.c -o start-service
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>

#define ERROR -1  //define error status integer as -1

void fatal(char message[])//handle fatal errors
{
printf("fatal error while %s \n", message);
exit(-1);
}

void usage()//display usage message and exit
{
printf("usage: start-service [port-number]\n");
exit(1);
}

int main(int *argc,char *argv[])
{
if(argc<1) usage();//check if the binary was executed correctly

int port=atoi(argv[1]);//accept port number for the service to run on from command line

int sockfd, newsockfd; /*variables to fetch file descriptors returned by socket() and bind()*/
int return_val; //fetch random return values
socklen_t sin_size;
struct sockaddr_in server, client; //internet socket addresses of server and client
char buffer[256]; //a character array to store stuff
bzero(buffer, 255); //zero out the buffer at index 255
sockfd=socket(AF_INET, SOCK_STREAM, 0); //initiate a call to socket()
if(sockfd==-1) fatal("calling socket"); //error handling

server.sin_family=AF_INET; //define the protocol family
server.sin_port=htons(port);//host to network short byte order
server.sin_addr.s_addr=0;//automatically fill with my IP
memset(&(server.sin_zero), '\0', 8); // Zero the rest of the struct.


return_val=bind(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr) );/*bind to a given socket file descriptor*/

if(return_val==-1) fatal("binding to socket"); //error handling

return_val=listen(sockfd, 10);/*start listening on the given socket file descriptor and queue 10 connections at the most.... the server will refuse further connections after 10 are already in the queue*/
if(return_val==-1)fatal("listening on socket");//error handling

while(1)
{
sin_size = sizeof (struct sockaddr_in);
newsockfd=accept(sockfd, (struct sockaddr *)&client, &sin_size);
if(newsockfd==-1) fatal("accepting connection");//error handling
printf("server: got connection from %s port %d\n",
inet_ntoa(client.sin_addr), ntohs(client.sin_port));
send(newsockfd, "Hello, world!\n", 13, 0);/*send a 13 character string to the client using the new socket file descriptor sent by the client*/
bzero(buffer,256);//zero out the buffer at 256th index
     return_val = read(newsockfd,buffer,255);//read data from the client into buffer
     if (return_val < 0) fatal("reading from socket");//error handling
     printf("Here is the message: %s\n",buffer);//print out the transferred data

return_val = write(newsockfd,"I got your message",18);/*notify the client about message arrival*/
     if (return_val < 0) fatal("writing to socket");//error handling

printf("%s at port %d sent a message : ",inet_ntoa(client.sin_addr), ntohs(client.sin_port));//print out
printf(buffer);//the message
}
return 0;
}
