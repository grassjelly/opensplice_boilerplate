#ifndef BOILERPLATEDCPS_IMPL_H_
#define BOILERPLATEDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_Boilerplate.h"
#include "TypeSupportMetaHolder.h"
#include "TypeSupport.h"
#include "FooDataWriter_impl.h"
#include "FooDataReader_impl.h"
#include "FooDataReaderView_impl.h"


class  TemplateTypeSupportMetaHolder : public ::DDS::OpenSplice::TypeSupportMetaHolder
{
public:
    TemplateTypeSupportMetaHolder ();
    virtual ~TemplateTypeSupportMetaHolder ();

private:
    ::DDS::OpenSplice::DataWriter * create_datawriter ();

    ::DDS::OpenSplice::DataReader * create_datareader ();

    ::DDS::OpenSplice::DataReaderView * create_view ();
};

class  TemplateTypeSupport : public virtual TemplateTypeSupportInterface,
                                                   public ::DDS::OpenSplice::TypeSupport
{
public:
    TemplateTypeSupport ();

    virtual ~TemplateTypeSupport ();

private:
    TemplateTypeSupport (const TemplateTypeSupport &);

    void operator= (const TemplateTypeSupport &);
};

typedef TemplateTypeSupportInterface_var TemplateTypeSupport_var;
typedef TemplateTypeSupportInterface_ptr TemplateTypeSupport_ptr;

class  TemplateDataWriter_impl : public virtual TemplateDataWriter,
                                                       public ::DDS::OpenSplice::FooDataWriter_impl
{
    friend class DDS::OpenSplice::Publisher;
    friend class TemplateTypeSupportMetaHolder;

public:
    virtual ::DDS::InstanceHandle_t register_instance (
        const Template & instance_data) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
        const Template & instance_data,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance (
        const Template & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
        const Template & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write (
        const Template & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write_w_timestamp (
        const Template & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose (
        const Template & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp (
        const Template & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose (
        const Template & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose_w_timestamp (
        const Template & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value (
        Template & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance (
        const Template & instance_data) THROW_ORB_EXCEPTIONS;

protected:
    TemplateDataWriter_impl ();

    virtual ~TemplateDataWriter_impl ();

    virtual DDS::ReturnCode_t init (
                    DDS::OpenSplice::Publisher *publisher,
                    DDS::OpenSplice::DomainParticipant *participant,
                    const DDS::DataWriterQos &qos,
                    DDS::OpenSplice::Topic *a_topic,
                    const char *name,
                    DDS::OpenSplice::cxxCopyIn copyIn,
                    DDS::OpenSplice::cxxCopyOut copyOut);

private:
    TemplateDataWriter_impl (const TemplateDataWriter_impl &);

    void operator= (const TemplateDataWriter &);
};

class  TemplateDataReader_impl : public virtual TemplateDataReader,
                                                       public ::DDS::OpenSplice::FooDataReader_impl
{
    friend class DDS::OpenSplice::Subscriber;
    friend class TemplateTypeSupportMetaHolder;
    friend class TemplateDataReaderView_impl;

public:
    virtual ::DDS::ReturnCode_t read (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample (
        Template & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample (
        Template & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value (
        Template & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance (
        const Template & instance) THROW_ORB_EXCEPTIONS;

protected:
    TemplateDataReader_impl ();

    virtual ~TemplateDataReader_impl ();

    DDS::ReturnCode_t init (
            DDS::OpenSplice::Subscriber *subscriber,
            const DDS::DataReaderQos &qos,
            DDS::OpenSplice::TopicDescription *a_topic,
            const char *name,
            DDS::OpenSplice::cxxCopyIn copyIn,
            DDS::OpenSplice::cxxCopyOut copyOut);

    static void* dataSeqAlloc (
        void * data_values,
        DDS::ULong len);

    static void dataSeqLength (
        void * data_values,
        DDS::ULong len);

    static void * dataSeqGetBuffer (
        void * data_values,
        DDS::ULong index);

    static void dataSeqCopyOut (
        const void * from,
        void * received_data);
    static void copyDataOut(const void *from, void *to);

private:
    TemplateDataReader_impl (const TemplateDataReader &);
    void operator= (const TemplateDataReader &);

    static ::DDS::ReturnCode_t check_preconditions (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples);
};

class  TemplateDataReaderView_impl : public virtual TemplateDataReaderView,
                                                           public ::DDS::OpenSplice::FooDataReaderView_impl
{
    friend class DDS::OpenSplice::DataReader;
    friend class TemplateTypeSupportMetaHolder;

public:
    virtual ::DDS::ReturnCode_t read (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample (
        Template & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample (
        Template & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan (
        TemplateSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value (
        Template & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance (
        const Template & instance) THROW_ORB_EXCEPTIONS;

protected:
    TemplateDataReaderView_impl ();

    virtual ~TemplateDataReaderView_impl ();

    virtual DDS::ReturnCode_t init (
        DDS::OpenSplice::DataReader *reader,
        const char *name,
        const DDS::DataReaderViewQos &qos,
        DDS::OpenSplice::cxxCopyIn copyIn,
        DDS::OpenSplice::cxxCopyOut copyOut);

private:
    TemplateDataReaderView_impl (const TemplateDataReaderView &);

    void operator= (const TemplateDataReaderView &);
};

class  SensorTypeSupportMetaHolder : public ::DDS::OpenSplice::TypeSupportMetaHolder
{
public:
    SensorTypeSupportMetaHolder ();
    virtual ~SensorTypeSupportMetaHolder ();

private:
    ::DDS::OpenSplice::DataWriter * create_datawriter ();

    ::DDS::OpenSplice::DataReader * create_datareader ();

    ::DDS::OpenSplice::DataReaderView * create_view ();
};

class  SensorTypeSupport : public virtual SensorTypeSupportInterface,
                                                   public ::DDS::OpenSplice::TypeSupport
{
public:
    SensorTypeSupport ();

    virtual ~SensorTypeSupport ();

private:
    SensorTypeSupport (const SensorTypeSupport &);

    void operator= (const SensorTypeSupport &);
};

typedef SensorTypeSupportInterface_var SensorTypeSupport_var;
typedef SensorTypeSupportInterface_ptr SensorTypeSupport_ptr;

class  SensorDataWriter_impl : public virtual SensorDataWriter,
                                                       public ::DDS::OpenSplice::FooDataWriter_impl
{
    friend class DDS::OpenSplice::Publisher;
    friend class SensorTypeSupportMetaHolder;

public:
    virtual ::DDS::InstanceHandle_t register_instance (
        const Sensor & instance_data) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
        const Sensor & instance_data,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance (
        const Sensor & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
        const Sensor & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write (
        const Sensor & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t write_w_timestamp (
        const Sensor & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose (
        const Sensor & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp (
        const Sensor & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose (
        const Sensor & instance_data,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t writedispose_w_timestamp (
        const Sensor & instance_data,
        ::DDS::InstanceHandle_t handle,
        const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value (
        Sensor & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance (
        const Sensor & instance_data) THROW_ORB_EXCEPTIONS;

protected:
    SensorDataWriter_impl ();

    virtual ~SensorDataWriter_impl ();

    virtual DDS::ReturnCode_t init (
                    DDS::OpenSplice::Publisher *publisher,
                    DDS::OpenSplice::DomainParticipant *participant,
                    const DDS::DataWriterQos &qos,
                    DDS::OpenSplice::Topic *a_topic,
                    const char *name,
                    DDS::OpenSplice::cxxCopyIn copyIn,
                    DDS::OpenSplice::cxxCopyOut copyOut);

private:
    SensorDataWriter_impl (const SensorDataWriter_impl &);

    void operator= (const SensorDataWriter &);
};

class  SensorDataReader_impl : public virtual SensorDataReader,
                                                       public ::DDS::OpenSplice::FooDataReader_impl
{
    friend class DDS::OpenSplice::Subscriber;
    friend class SensorTypeSupportMetaHolder;
    friend class SensorDataReaderView_impl;

public:
    virtual ::DDS::ReturnCode_t read (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample (
        Sensor & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample (
        Sensor & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value (
        Sensor & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance (
        const Sensor & instance) THROW_ORB_EXCEPTIONS;

protected:
    SensorDataReader_impl ();

    virtual ~SensorDataReader_impl ();

    DDS::ReturnCode_t init (
            DDS::OpenSplice::Subscriber *subscriber,
            const DDS::DataReaderQos &qos,
            DDS::OpenSplice::TopicDescription *a_topic,
            const char *name,
            DDS::OpenSplice::cxxCopyIn copyIn,
            DDS::OpenSplice::cxxCopyOut copyOut);

    static void* dataSeqAlloc (
        void * data_values,
        DDS::ULong len);

    static void dataSeqLength (
        void * data_values,
        DDS::ULong len);

    static void * dataSeqGetBuffer (
        void * data_values,
        DDS::ULong index);

    static void dataSeqCopyOut (
        const void * from,
        void * received_data);
    static void copyDataOut(const void *from, void *to);

private:
    SensorDataReader_impl (const SensorDataReader &);
    void operator= (const SensorDataReader &);

    static ::DDS::ReturnCode_t check_preconditions (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples);
};

class  SensorDataReaderView_impl : public virtual SensorDataReaderView,
                                                           public ::DDS::OpenSplice::FooDataReaderView_impl
{
    friend class DDS::OpenSplice::DataReader;
    friend class SensorTypeSupportMetaHolder;

public:
    virtual ::DDS::ReturnCode_t read (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_w_condition (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_w_condition (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_sample (
        Sensor & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_sample (
        Sensor & received_data,
        ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_instance (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_instance (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::SampleStateMask sample_states,
        ::DDS::ViewStateMask view_states,
        ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq,
        ::DDS::Long max_samples,
        ::DDS::InstanceHandle_t a_handle,
        ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t return_loan (
        SensorSeq & received_data,
        ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::ReturnCode_t get_key_value (
        Sensor & key_holder,
        ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

    virtual ::DDS::InstanceHandle_t lookup_instance (
        const Sensor & instance) THROW_ORB_EXCEPTIONS;

protected:
    SensorDataReaderView_impl ();

    virtual ~SensorDataReaderView_impl ();

    virtual DDS::ReturnCode_t init (
        DDS::OpenSplice::DataReader *reader,
        const char *name,
        const DDS::DataReaderViewQos &qos,
        DDS::OpenSplice::cxxCopyIn copyIn,
        DDS::OpenSplice::cxxCopyOut copyOut);

private:
    SensorDataReaderView_impl (const SensorDataReaderView &);

    void operator= (const SensorDataReaderView &);
};

#undef OS_API
#endif
