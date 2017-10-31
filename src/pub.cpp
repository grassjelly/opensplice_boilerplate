
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

    Boilerplate::Publisher pub(par, (char*)"HelloWorldData_Msg");
    for(;;){
        Msg testmsg; /* Example on Stack */
        testmsg.userID = 1;
        testmsg.message = DDS::string_dup("Hello World");
        pub.publish(testmsg);
        os_nanoSleep(delay_200ms);
        
    }

    
    //delete publisher
    pub.kill();
    //delete participant
    par.kill();
    return 0;
}
