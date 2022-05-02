#include <iostream>
#include "UserInterfaceLinux.dll"
#include <string>
#define Port_Chasing_Server 8080
#define Port_Main_Server 8002
using namespace std;



int main(int argc, char const *argv[])
{
    char massage[50]="Str problem";
    UserInterfaceLinux user;
    user.connection_to_cashing_server(Port_Chasing_Server, massage);
    sleep(2);
    user.connection_to_main_server(Port_Main_Server, massage);
    return 0;
}