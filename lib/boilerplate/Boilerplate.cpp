#include "Boilerplate.h"

Boilerplate::Publisher::Publisher(Participant  &participant_object, char * topic_name)
{
  participant = participant_object.get_participant();
  partition = participant_object.get_partition();
  topicName = topic_name;    
  init_publisher();
}

void Boilerplate::Publisher::init_publisher()
{

  //=======register type======
  MsgTypeSupport_var mt = new MsgTypeSupport();
  ts = mt.in();

  typeName = ts->get_type_name();
  status = ts->register_type(participant.in(), typeName);
  checkStatus(status, "register_type");

  //=======create topic=======
  status = participant->get_default_topic_qos(reliable_topic_qos);
  checkStatus(status, "DDS::DomainParticipant::get_default_topic_qos");
  reliable_topic_qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
  reliable_topic_qos.durability.kind = TRANSIENT_DURABILITY_QOS;

  /* Make the tailored QoS the new default. */
  status = participant->set_default_topic_qos(reliable_topic_qos);
  checkStatus(status, "DDS::DomainParticipant::set_default_topic_qos");

  /* Use the changed policy when defining the HelloWorld topic */
  topic = participant->create_topic(topicName, typeName, reliable_topic_qos,
    NULL, STATUS_MASK_NONE);
  checkHandle(topic.in(), "DDS::DomainParticipant::create_topic ()");

  //========create publisher=======
  status = participant->get_default_publisher_qos(pub_qos);
  checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");
  pub_qos.partition.name.length(1);
  pub_qos.partition.name[0] = partition;

  publisher = participant->create_publisher(pub_qos, NULL, STATUS_MASK_NONE);
  checkHandle(publisher.in(), "DDS::DomainParticipant::create_publisher");

  //========create data writer======
  status = publisher->get_default_datawriter_qos(dw_qos);
  checkStatus(status, "DDS::DomainParticipant::get_default_publisher_qos");
  status = publisher->copy_from_topic_qos(dw_qos, reliable_topic_qos);
  checkStatus(status, "DDS::Publisher::copy_from_topic_qos");
  // Set autodispose to false so that you can start
  // the subscriber after the publisher
  // If autodispose_unregistered_instances is set to true (default value),
  // you will have to start the subscriber before the publisher
  dw_qos.writer_data_lifecycle.autodispose_unregistered_instances = false;
  writer = publisher->create_datawriter(topic.in(), dw_qos, NULL,
    STATUS_MASK_NONE);
  checkHandle(writer, "DDS::Publisher::create_datawriter");


  //========publish events=========
  DataWriter_var dwriter = DataWriter::_duplicate(writer.in());
  HelloWorldWriter = MsgDataWriter::_narrow(dwriter.in());
}

void Boilerplate::Publisher::publish(Msg instance)
{
  status = HelloWorldWriter->write(instance, DDS::HANDLE_NIL);
  checkStatus(status, "MsgDataWriter::write");
}

void Boilerplate::Publisher::kill()
{

  //========delete writer==========
  status = publisher->delete_datawriter(writer);
  checkStatus(status, "DDS::Publisher::delete_datawriter ");

  //========delete publisher=========
  status = participant->delete_publisher(publisher.in());
  checkStatus(status, "DDS::DomainParticipant::delete_publisher ");

  //========delete topic=========
  status = participant->delete_topic(topic);
  checkStatus(status, "DDS.DomainParticipant.delete_topic");
}

Boilerplate::Subscriber::Subscriber(Participant  &participant_object, char * topic_name)
{
  participant = participant_object.get_participant();
  partition = participant_object.get_partition();
  topicName = topic_name;    
  init_subscriber();
}

void Boilerplate::Subscriber::init_subscriber()
{

  //=======register type======
  MsgTypeSupport_var mt = new MsgTypeSupport();
  ts = mt.in();

  typeName = ts->get_type_name();
  status = ts->register_type(participant.in(), typeName);
  checkStatus(status, "register_type");

  //=======create topic=======
  status = participant->get_default_topic_qos(reliable_topic_qos);
  checkStatus(status, "DDS::DomainParticipant::get_default_topic_qos");
  reliable_topic_qos.reliability.kind = RELIABLE_RELIABILITY_QOS;
  reliable_topic_qos.durability.kind = TRANSIENT_DURABILITY_QOS;

  /* Make the tailored QoS the new default. */
  status = participant->set_default_topic_qos(reliable_topic_qos);
  checkStatus(status, "DDS::DomainParticipant::set_default_topic_qos");

  /* Use the changed policy when defining the HelloWorld topic */
  topic = participant->create_topic(topicName, typeName, reliable_topic_qos,
    NULL, STATUS_MASK_NONE);
  checkHandle(topic.in(), "DDS::DomainParticipant::create_topic ()");

  //========create subscriber=======
  status = participant->get_default_subscriber_qos(sub_qos);
  checkStatus(status, "DDS::DomainParticipant::get_default_subscriber_qos");
  sub_qos.partition.name.length(1);
  sub_qos.partition.name[0] = partition;
  subscriber = participant->create_subscriber(sub_qos, NULL, STATUS_MASK_NONE);
  checkHandle(subscriber.in(), "DDS::DomainParticipant::create_subscriber");

  // //========create data reader======
  reader = subscriber->create_datareader(topic.in(),
  DATAREADER_QOS_USE_TOPIC_QOS, NULL, STATUS_MASK_NONE);
  checkHandle(reader, "DDS::Subscriber::create_datareader ()");

  DataReader_var dreader = DataReader::_duplicate(reader.in());;
  HelloWorldReader = MsgDataReader::_narrow(dreader.in());
  checkHandle(HelloWorldReader.in(), "MsgDataReader::_narrow");
}

void Boilerplate::Subscriber::read()
{
  SampleInfoSeq infoSeq;
  MsgSeq msgList;
  
  status = HelloWorldReader->take(msgList, infoSeq, LENGTH_UNLIMITED,
    ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
  checkStatus(status, "msgDataReader::take");
  msg_list = msgList;

  status = HelloWorldReader->return_loan(msgList, infoSeq);
  checkStatus(status, "MsgDataReader::return_loan");
}

void Boilerplate::Subscriber::kill()
{
  //========delete reader==========
  status = subscriber->delete_datareader(reader);
  checkStatus(status, "DDS::Subscriber::delete_datareader ");

  //========delete subscriber=========
  status = participant->delete_subscriber(subscriber);
  checkStatus(status, "DDS::DomainParticipant::delete_subscriber ");

  //========delete topic=========
  status = participant->delete_topic(topic);
  checkStatus(status, "DDS.DomainParticipant.delete_topic");
}