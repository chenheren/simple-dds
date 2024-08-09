#include <simple_dds/dds/publisher/DataWriter.h>

namespace simple_dds
{
namespace dds
{
InstanceHandle_t DataWriter::register_instance(
    void* instance)
{

}

InstanceHandle_t DataWriter::register_instance_w_timestamp(
    void* instance,
    Time_t timestamp)
{

}

ReturnCode_t DataWriter::unregister_instance(
    void* instance,
    InstanceHandle_t handle)
{

}

InstanceHandle_t DataWriter::unregister_instance_w_timestamp(
    void* instance,
    InstanceHandle_t handle,
    Time_t timestamp)
{

}

ReturnCode_t DataWriter::get_key_value(
    void* instance,
    InstanceHandle_t handle)
{

}

InstanceHandle_t DataWriter::lookup_instance(
    void* instance)
{

}

ReturnCode_t DataWriter::write(
    void* data,
    InstanceHandle_t handle)
{

}

ReturnCode_t DataWriter::write_w_timestamp(
    void* data,
    InstanceHandle_t handle,
    Time_t timestamp)
{

}

ReturnCode_t DataWriter::dispose(
    void* data,
    InstanceHandle_t handle)
{

}

ReturnCode_t DataWriter::dispose_w_timestamp(
    void* data,
    InstanceHandle_t handle,
    Time_t timestamp)
{

}

ReturnCode_t DataWriter::wait_for_acknowledgments(
    Duration_t max_wait)
{

}

ReturnCode_t DataWriter::get_liveliness_lost_status(
    LivelinessLostStatus& status)
{

}

ReturnCode_t DataWriter::get_offered_deadline_missed_status(
    OfferedDeadlineMissedStatus& status)
{

}

ReturnCode_t DataWriter::get_offered_incompatible_qos_status(
    OfferedIncompatibleQosStatus& status)
{

}

ReturnCode_t DataWriter::get_publication_matched_status(
    PublicationMatchedStatus& status)
{

}

Topic* DataWriter::get_topic()
{

}

Publisher* DataWriter::get_publisher()
{

}

ReturnCode_t DataWriter::assert_liveliness()
{

}

ReturnCode_t DataWriter::get_matched_subscription_data(
    SubscriptionBuiltinTopicData& subscription_data,
    InstanceHandle_t subscription_handle)
{

}

ReturnCode_t DataWriter::get_matched_subscriptions(
    std::vector<InstanceHandle_t>& subscription_handles)
{

}
}
}