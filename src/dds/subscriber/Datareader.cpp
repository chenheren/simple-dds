#include <simple_dds/dds/subscriber/DataReader.h>

namespace simple_dds
{
namespace dds
{
class DataReader::Impl
{
public:

};

ReturnCode_t DataReader::read(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    const std::vector<SampleRejectedStatusKind> &sample_states,
    const std::vector<ViewStateKind> &view_states,
    const std::vector<InstanceStateKind> &instance_states)
{

}

ReturnCode_t DataReader::take(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    const std::vector<SampleRejectedStatusKind> &sample_states,
    const std::vector<ViewStateKind> &view_states,
    const std::vector<InstanceStateKind> &instance_states)
{

}

ReturnCode_t DataReader::read_w_condition(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    const ReadCondition &condition)
{

}

ReturnCode_t DataReader::take_w_condition(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    const ReadCondition &condition)
{

}

ReturnCode_t DataReader::read_next_sample(
    void *data,
    const SampleInfo *sample_info)
{

}

ReturnCode_t DataReader::take_next_sample(
    void *data,
    const SampleInfo *sample_info)
{

}

ReturnCode_t DataReader::read_instance(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    InstanceHandle_t handle,
    const std::vector<SampleRejectedStatusKind> &sample_states,
    const std::vector<ViewStateKind> &view_states,
    const std::vector<InstanceStateKind> &instance_states)
{

}

ReturnCode_t DataReader::take_instance(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    InstanceHandle_t handle,
    const std::vector<SampleRejectedStatusKind> &sample_states,
    const std::vector<ViewStateKind> &view_states,
    const std::vector<InstanceStateKind> &instance_states)
{

}

ReturnCode_t DataReader::read_next_instance(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    InstanceHandle_t previous_handle,
    const std::vector<SampleRejectedStatusKind> &sample_states,
    const std::vector<ViewStateKind> &view_states,
    const std::vector<InstanceStateKind> &instance_states)
{

}

ReturnCode_t DataReader::take_next_instance(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    InstanceHandle_t previous_handle,
    const std::vector<SampleRejectedStatusKind> &sample_states,
    const std::vector<ViewStateKind> &view_states,
    const std::vector<InstanceStateKind> &instance_states)
{

}

ReturnCode_t DataReader::read_next_instance_w_condition(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    InstanceHandle_t previous_handle,
    ReadCondition condition)
{

}

ReturnCode_t DataReader::take_next_instance_w_condition(
    void **data,
    const std::vector<SampleInfo> &sample_infos,
    std::uint32_t max_samples,
    InstanceHandle_t previous_handle,
    ReadCondition condition)
{

}

ReturnCode_t DataReader::return_loan(
    void **data,
    const std::vector<SampleInfo> &sample_infos)
{

}

ReturnCode_t DataReader::get_key_value(
    void *key_holder,
    InstanceHandle_t handle)
{

}

InstanceHandle_t DataReader::lookup_instance(
    void *data)
{

}

ReadCondition *DataReader::create_readcondition(
    const std::vector<SampleRejectedStatusKind> &sample_states,
    const std::vector<ViewStateKind> &view_states,
    const std::vector<InstanceStateKind> &instance_states)
{

}

QueryCondition DataReader::create_querycondition(
    const std::vector<SampleRejectedStatusKind> &sample_states,
    const std::vector<ViewStateKind> &view_states,
    const std::vector<InstanceStateKind> &instance_states,
    const std::string &query_expression,
    const std::vector<std::string> &query_parameters)
{

}

ReturnCode_t DataReader::delete_readcondition(
    ReadCondition *condition)
{

}

ReturnCode_t DataReader::get_liveliness_changed_status(
    LivelinessChangedStatus &status)
{

}

ReturnCode_t DataReader::get_requested_deadline_missed_status(
    RequestedDeadlineMissedStatus &status)
{

}

ReturnCode_t DataReader::get_requested_incompatible_qos_status(
    RequestedIncompatibleQosStatus &status)
{

}

ReturnCode_t DataReader::get_sample_lost_status(
    SampleLostStatus &status)
{

}

ReturnCode_t DataReader::get_sample_rejected_status(
    SampleRejectedStatus &status)
{

}

ReturnCode_t DataReader::get_subscription_matched_status(
    SubscriptionMatchedStatus &status)
{

}

TopicDescription *DataReader::get_topicdescription()
{

}

Subscriber *DataReader::get_subscriber()
{

}

ReturnCode_t DataReader::delete_contained_entities()
{

}

ReturnCode_t DataReader::wait_for_historical_data(
    const Duration_t &max_wait)
{

}

ReturnCode_t DataReader::get_matched_publication_data(
    PublicationBuiltinTopicData &publication_data,
    InstanceHandle_t publication_handle)
{

}

ReturnCode_t DataReader::get_matched_publications(
    const std::vector<InstanceHandle_t> &publication_handles)
{

}

}
}