#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//#define Port_Chasing_Server 8080

using namespace std;

string Generic_Random_IP()
{
    string random_IP;
    int IP = rand()%254+1;
    std::string s  = std::to_string(IP);
    random_IP=s+".";
    IP = rand()%254+1;
    s  = std::to_string(IP);
    random_IP=random_IP+s+".";
    IP = rand()%254+1;
    s  = std::to_string(IP);
    random_IP=random_IP+s+".";
    IP = rand()%254+1;
    s  = std::to_string(IP);
    random_IP=random_IP+s;
    return random_IP;
}


int connection_to_cashing_server(int Port, char *massage)
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
    string IP_client=Generic_Random_IP();
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

    strcpy(massage, IP_client.c_str());
    //Sent ip to cashing server
    send(sock , massage  , strlen(massage), 0 );
    valread = read( sock , buffer, 1024);
    cout<<buffer<<endl;
    string id;
    getline(cin, id);
    strcpy(massage, id.c_str());
    send(sock , massage  , strlen(massage), 0 );
    
    valread = read( sock , buffer1, 1024);
    cout<<buffer1<<endl;
    close(sock);
    return 0;
}

string option_of_program()
{

    string massage;
    int number;
    cout<<"*************************************************************************************"<<endl;
    cout<<"1. Chestotno razpredelenie"<<endl;
    cout<<"2. Merki na centralnata tendenciq! "<<endl;
    cout<<"3. Merki na razseivane"<<endl;
    cout<<"4. Korelacionen analiz na kachenite yprajneiq!"<<endl;
    cout<<"For chose option please insert number!"<<endl;
    cin>>number;
    switch (number){
    case 1:
    {
         massage="option 1";
         break;
    }
    case 2: 
    {
        massage="option 2";
        break;
    }
    case 3:
    {
        massage="option 3";
        break;
    }
    case 4:
    {
        massage="option 4";
        break;
    }
    }
    return massage;
}

int connection_to_main_server(int Port, char *massage)
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
    string IP_client=Generic_Random_IP();
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
    valread = read( sock , buffer, 1024);
    cout<<buffer<<endl;
    cout<<"*******************************************************************************"<<endl;
    string option=option_of_program();
    strcpy(massage, option.c_str());
    send(sock , massage  , strlen(massage), 0 );
    valread = read( sock , buffer1, 1024);
    cout<<buffer1<<endl;
    bzero(buffer, sizeof(buffer));
    valread = read( sock , buffer, 1024);
    cout<<buffer;
    bzero(buffer, sizeof(buffer));
    close(sock);
    return 0;
}