#ifndef Sensor_H
#define Sensor_H

#include <iostream>
#include "ccpp_dds_dcps.h"
#include "CheckStatus.h"
#include "Participant.h"
#include "ccpp_Boilerplate.h"

using namespace DDS;
namespace SensorMsg
{
    class Publisher
    {
        void init_publisher();
        
        DomainParticipant_var participant;
        ReturnCode_t status;
        
        String_var partition;   
        char * topicName;
        
        TypeSupport * ts;   
        DDS::String_var typeName;
        
        Topic_var topic;
        TopicQos reliable_topic_qos;
        Publisher_var publisher;
        PublisherQos pub_qos;
        
        DataWriterQos dw_qos;
        DataWriter_var writer;
        SensorDataWriter_var myWriter;

        public:
            Publisher(Participant  &, char * );
            void publish(Sensor);
            void kill();
    };

    class Subscriber
    {
        void init_subscriber();
        
        DomainParticipant_var participant;
        ReturnCode_t status;
        
        String_var partition;    
        char * topicName;

        TypeSupport * ts;   
        DDS::String_var typeName;
        
        Topic_var topic;
        TopicQos reliable_topic_qos;
        Subscriber_var subscriber;
        SubscriberQos sub_qos;
        
        DataReader_var reader;
        SensorDataReader_var myReader;

        public:
            Subscriber(Participant  &, char * );
            SensorSeq msg_list;
            void read();
            void kill();
    };

}


#endif 
