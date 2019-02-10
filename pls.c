/*
Author - k4m1k4z13r
Copyright: Copy what you can
*/
//Compile - gcc ./pls.c -o pls
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>

#define ERROR -1  //define error status integer as -1

int subtree = 0;

void fatal(char message[])//handle fatal errors
{
// if statement prevents message flooding
if(subtree < 1) { // change value '1' to allow additional error messages to display
  printf("fatal error while %s \n Suppressing further errors in this subtree \n", message);
  subtree += 1;
  }
}

void usage()//display usage message and exit
{
printf("usage: ./pls [IP address of remote host]\n");
exit(1);
}

int main(int argc,char *argv[])
{
if(argc<1) usage();
int sockfd;
int n=65535;//store the number of ports in TCP/IP
struct sockaddr_in remote_host;
int i;//an integer variable to iterate through the ports
remote_host.sin_family=AF_INET;
remote_host.sin_addr.s_addr=inet_addr(argv[1]);//provide IP of remote host
memset(&(remote_host.sin_zero), '\0', 8); // Zero the rest of the struct.

printf("----------Open ports of host %s------------\n", inet_ntoa(remote_host.sin_addr));
for(i=0;i<=n;i++){//iterate through all TCP/IP ports.... 0 t0 65535

remote_host.sin_port=htons(i);//provide port number




sockfd=socket(AF_INET, SOCK_STREAM, 0);//create a tcp socket and fetch the file descriptor
	if(sockfd==-1) fatal("creating socket");//error handling

if(connect(sockfd, (struct sockaddr *)&remote_host,  sizeof(struct sockaddr_in))==ERROR) 
continue;//try connecting to remote host and try next if connect fails....

else
{
printf("Port %d was open at host %s \n", i, inet_ntoa(remote_host.sin_addr));
printf("=================================================================================\n");
}
}
return 0;
}
