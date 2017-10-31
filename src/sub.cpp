
// -- Std C/C++ Include
#include <string>
#include <sstream>
#include <iostream>
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono> 

#include "Boilerplate.h"
#include "Participant.h"

using namespace Boilerplate;

int main(int argc, char* argv[])
{
    os_time delay_200ms = { 0, 200000000 };
    
    Participant par("HelloWorld example", 1);

    Boilerplate::Subscriber sub(par, (char*)"HelloWorldData_Msg");

    for(;;)
    {
        sub.read();        
        for (DDS::ULong j = 0; j < sub.msg_list.length(); j++)
        {
            cout << "=== [Subscriber] message received :" << endl;
            cout << "    userID  : " << sub.msg_list[j].userID << endl;
            cout << "    Message : \"" << sub.msg_list[j].message << "\"" << endl;
        }    
        
    }
    //delete subscriber
    sub.kill();
    //delete participant
    par.kill();
    return 0;
}
