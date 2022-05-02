#include <iostream>
#include <thread>
#include "I_UserAccess.dll"
#include <mutex> 
#define Port_Client 8080
#define Port_Client1 8081

#define Port_Server 8001
#define Port_Server1 8003
using namespace std;

void thread_server(int Port_Main_Server, int Port_client)
{
    Cashing_Server cashing_server;
    int i=0;
    char massage[50]="Str problem";
    i=cashing_server.conection_client(Port_client, massage);
    cashing_server.connection_to_main_server(Port_Main_Server, massage, i);
}

int main(int argc, char const *argv[])
{

    std::thread client (thread_server,Port_Server, Port_Client);
    client.join();
    sleep(2);
    std::thread client1 (thread_server,Port_Server1, Port_Client1);
    client1.join();
    return 0;
}