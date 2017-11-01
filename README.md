# opensplice_boilerplate
This package allows a user to create multiple instances of publisher and subscriber within one node. The API supports instances of different message types defined in an IDL file.

## Adding new IDL file:

1. Add your own idl file in the idl folder.
2. Generate the codes:
    
    $ ./gencode

This script will auto:  
- Generate the DDS codes for the idl files you have created. 
- Generate boilerplates specific to the message type so you can use the API.
- Generate a CMakeLists.txt for the boilerplates. This must be included in the main CMakeLists.txt so you can use it in the API. See No.3 .

3. Add the generated codes and boilerplates in the main CMakeLists.txt:

        include(lib/boilerplate/types/Template/CMakeLists.txt)
        include(lib/boilerplate/types/Sensor/CMakeLists.txt)

        ADD_LIBRARY (MGR_SRC
                lib/boilerplate/template/CheckStatus.cpp
                lib/boilerplate/template/Participant.cpp
                ${Sensor}
                ${Template}
        )

## Using the API:

1. Include your new message type's header files:
    
        #include "Template.h"
        #include "Sensor.h"

2. Create participant:
    
        Participant par("Node Name", DOMAIN_ID);


3. Creating a Publisher. Remember to add "Msg" when calling the namespace ie. <MessageType>Msg:
  
        SensorMsg::Publisher pub(par, (char*)"HelloWorldData_Msg2");

TemplateMsg can be any message based on the idl file you have created.

4. Publish:
        
        //create message object
        Sensor testmsg;
        
        //populate the data
        testmsg.userID = 1;
        testmsg.message = DDS::string_dup("Hello World");
        
        //publish testmsg
        pub.publish(testmsg);

5. Creating a Subscriber. Remember to add "Msg" when calling the namespace ie. <MessageType>Msg:

        SensorMsg::Subscriber sub(par, (char*)"HelloWorldData_Msg2");


TemplateMsg can be any message based on the idl file you have created.

6. Subscribing and receiving data:

        sub.read();        
        for (DDS::ULong j = 0; j < sub.msg_list.length(); j++)
        {
            cout << "=== [Subscriber] message received :" << endl;
            cout << "    userID  : " << sub.msg_list[j].userID << endl;
            cout << "    Message : \"" << sub.msg_list[j].message << "\"" << endl;
        }    