#include <iostream>
#include <thread>
#include "I_UserManger.h"
#include <mutex> 
#define Cahsing_Server1 8001
#define Port_Client1 8002
#define Cahsing_Server2 8003
#define Port_Client2 8004
using namespace std;

void thread_server(int Port_casing_Server, int Port_Client)
{
        int i=0;
    char massage[50]="Str problem";
    //std::thread client (conection_client,Port_Client, massage);
    //std::thread client1 (conection_client,Port_Client, massage);
    i=conection_cashing_Server(Port_casing_Server, massage);
    cout<<i<<endl;
    string id="1219";
    cout<<id<<endl;
    sleep(1);
    if(i==10)
    {
    conection_to_client(Port_Client, massage);
    }
}

int main(int argc, char const *argv[])
{
    //int i=0;
    //char massage[50]="Str problem";
    std::thread client (thread_server,Cahsing_Server1, Port_Client1);
    std::thread client1 (thread_server,Cahsing_Server2, Port_Client2);

    client.join();
    //sleep(1);
    client1.join();
    //std::thread client1 (conection_client,Port_Client, massage);
    //i=conection_cashing_Server(Cahsing_Server1, massage);
    //cout<<i<<endl;
    //string id="1219";
    //cout<<id<<endl;
    //sleep(1);
    //if(i==10)
    //{
    //conection_to_client(Port_Client1, massage);
    //}
    return 0;
}