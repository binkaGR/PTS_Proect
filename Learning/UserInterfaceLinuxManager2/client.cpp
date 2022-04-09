#include <iostream>
#include "UserInterfaceLinux.h"
#include <string>
#define Port_Chasing_Server 8081
#define Port_Main_Server 8004
//#define Port_Chasing_Server 8115
using namespace std;



int main(int argc, char const *argv[])
{
    char massage[50]="Str problem";
    connection_to_cashing_server(Port_Chasing_Server, massage);
    sleep(2);
    connection_to_main_server(Port_Main_Server, massage);
    return 0;
}