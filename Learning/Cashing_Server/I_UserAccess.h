#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <string.h>
using namespace std;
int checking_access(int id)
{
    if(id==1219)
    {
        return id;
    }
    else 
        return 0;
}

int  conection_client(int Port, char *massage)

{   int server_fd, new_socket, valread, listenfd;
	struct sockaddr_in address;
    //char *massage;
	int opt = 0;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
    char buffer1[1024] = {0};
 // Creating socket file descriptor
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&address, sizeof(address));
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( Port);
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    //cin.ignore();
	string Massage="Hello please insert your ID: ";
    strcpy(massage, Massage.c_str());
    send(new_socket , massage , strlen(massage) , 0 );
    valread = read( new_socket , buffer1, 1024);
    printf("%s\n",buffer1 );
    int ID = stoi(buffer1);
    cout<<ID<<endl;

    if(checking_access(ID)!=0)
    {
        string Massage="You can accesss main server! ";
        strcpy(massage, Massage.c_str());
        send(new_socket , massage , strlen(massage) , 0 );
        return 10;
    }
    else
    {
        string Massage="You can't access accesss main server! ";
        strcpy(massage, Massage.c_str());
        send(new_socket , massage , strlen(massage) , 0 );
        return 0;
    }
    close(new_socket);
    return 0;
}


int connection_to_main_server(int Port, char *massage, int i)
{
    int sock=0, valread;
    struct  sockaddr_in serv_addr;
    char buffer[1024];
    char buffer1[1024];
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(Port);
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.5", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

    //Sent ip to cashing server
    if(i!=0)
    {
    //massage="1219";
    //send(sock , massage  , strlen(massage), 0 );
    massage="This client can connect wit you! ";
    send(sock , massage  , strlen(massage), 0 );
    }
    else
    {
    massage="This client can't  connect wit you! ";
    send(sock , massage  , strlen(massage), 0 );
    }
    valread = read( sock , buffer, 1024);
    cout<<buffer<<endl;
    close(sock);
    return 0;
}