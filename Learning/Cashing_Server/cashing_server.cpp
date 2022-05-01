#include <iostream>
#include <thread>
#include "I_UserAccess.h"
#include <mutex> 
#define Port_Client 8080
#define Port_Client1 8081

#define Port_Server 8001
#define Port_Server1 8003
using namespace std;

void thread_server(int Port_Main_Server, int Port_client)
{
    int i=0;
    char massage[50]="Str problem";
    i=conection_client(Port_client, massage);
    connection_to_main_server(Port_Main_Server, massage, i);
}

int main(int argc, char const *argv[])
{
    //int i=0;
    //char massage[50]="Str problem";
    std::thread client (thread_server,Port_Server, Port_Client);
    client.join();
    //sleep(2);
    //std::thread client1 (thread_server,Port_Server1, Port_Client1);
    //client1.join();
    //std::thread client1 (conection_client,Port_Client, massage);
    //i=conection_client(Port_Client, massage);
    //connection_to_main_server(Port_Server, massage, i);

    return 0;
}