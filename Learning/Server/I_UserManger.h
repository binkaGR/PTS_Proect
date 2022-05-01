#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <iomanip>
#include <math.h>
#include <fstream>
#include "Correllation.h"
using namespace std;

constexpr int CHAR_LENGTH = 4;



int  conection_cashing_Server(int Port, char *massage)

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
    printf("%s\n",buffer); 
    //valread = read( new_socket , buffer1, 1024);
    //printf("%s\n",buffer1 );
    //cin.ignore();
    if(strcmp(buffer,"This client can connect wit you! ")==0)
    {
        string Massage="Ok this client will be connect";
        strcpy(massage, Massage.c_str());
        send(new_socket , massage , strlen(massage) , 0 );
        return 10;
    }
    else
    {
        string Massage="Ok this  client can't be be connect";
        strcpy(massage, Massage.c_str());
        send(new_socket , massage , strlen(massage) , 0 );
        return 0;
    }
    close(new_socket);
    return 0;
}

int  conection_to_client(int Port, char *massage, char *information)

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
	string Massage="You are connection with server!";
    strcpy(massage, Massage.c_str());
    send(new_socket , massage , strlen(massage) , 0 );
    valread = read( new_socket , buffer, 1024);
    cout<<buffer<<endl;
    if(strcmp(buffer, "option 1") == 0)
    {
        massage="Data for option 1 will be send soon!";
        send(new_socket , massage , strlen(massage) , 0 );
    }
    else if(strcmp(buffer, "option 2") == 0)
    {
        massage="Data for option 2 will be send soon!";
        send(new_socket , massage , strlen(massage) , 0 );
    }
    else if(strcmp(buffer, "option 3") == 0)
    {
        massage="Data for option 3 will be send soon!";
        send(new_socket , massage , strlen(massage) , 0 );
    }else if(strcmp(buffer, "option 4") == 0)
    {
        massage="Data for option 4 will be send soon!";
        send(new_socket , massage , strlen(massage) , 0 );
        Carallestion corelation;
        if(corelation.function_correllation()==4)
        {
                cout<<"file is ready to send! "<<endl;
        }
        fstream file("correllation.txt", std::fstream::in);
        string myText;
        while (getline (file, myText))
            {
            myText=myText+"\n";
            strcpy(information, myText.c_str());
            send(new_socket , information , strlen(information) , 0 );
            }
                //valread = read( new_socket , buffer, 1024);
                //cout<<buffer<<endl;
            file.close();
    }
    else 
    {
        massage="Data is not correct! ";
        send(new_socket , massage , strlen(massage) , 0 );
    }
    
    close(new_socket);
    return 0;
}