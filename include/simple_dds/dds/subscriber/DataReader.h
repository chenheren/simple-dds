#pragma once

#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Status.h>
#include <simple_dds/dds/subscriber/SampleInfo.h>
#include <simple_dds/dds/subscriber/ReadCondition.h>
#include <simple_dds/dds/subscriber/QueryCondition.h>

namespace simple_dds
{
namespace dds
{
class Subscriber;
class TopicDescription;

class DataReader
{
public:
    ReturnCode_t read(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        const std::vector<SampleRejectedStatusKind> &sample_states,
        const std::vector<ViewStateKind> &view_states,
        const std::vector<InstanceStateKind> &instance_states);

    ReturnCode_t take(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        const std::vector<SampleRejectedStatusKind> &sample_states,
        const std::vector<ViewStateKind> &view_states,
        const std::vector<InstanceStateKind> &instance_states);

    ReturnCode_t read_w_condition(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        const ReadCondition &condition);

    ReturnCode_t take_w_condition(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        const ReadCondition &condition);

    ReturnCode_t read_next_sample(
        void *data,
        const SampleInfo *sample_info);

    ReturnCode_t take_next_sample(
        void *data,
        const SampleInfo *sample_info);

    ReturnCode_t read_instance(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        InstanceHandle_t handle,
        const std::vector<SampleRejectedStatusKind> &sample_states,
        const std::vector<ViewStateKind> &view_states,
        const std::vector<InstanceStateKind> &instance_states);

    ReturnCode_t take_instance(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        InstanceHandle_t handle,
        const std::vector<SampleRejectedStatusKind> &sample_states,
        const std::vector<ViewStateKind> &view_states,
        const std::vector<InstanceStateKind> &instance_states);

    ReturnCode_t read_next_instance(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        InstanceHandle_t previous_handle,
        const std::vector<SampleRejectedStatusKind> &sample_states,
        const std::vector<ViewStateKind> &view_states,
        const std::vector<InstanceStateKind> &instance_states);

    ReturnCode_t take_next_instance(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        InstanceHandle_t previous_handle,
        const std::vector<SampleRejectedStatusKind> &sample_states,
        const std::vector<ViewStateKind> &view_states,
        const std::vector<InstanceStateKind> &instance_states);

    ReturnCode_t read_next_instance_w_condition(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        InstanceHandle_t previous_handle,
        ReadCondition condition);

    ReturnCode_t take_next_instance_w_condition(
        void **data,
        const std::vector<SampleInfo> &sample_infos,
        std::uint32_t max_samples,
        InstanceHandle_t previous_handle,
        ReadCondition condition);

    ReturnCode_t return_loan(
        void **data,
        const std::vector<SampleInfo> &sample_infos);

    ReturnCode_t get_key_value(
        void *key_holder,
        InstanceHandle_t handle);

    InstanceHandle_t lookup_instance(
        void *data);

    ReadCondition *create_readcondition(
        const std::vector<SampleRejectedStatusKind> &sample_states,
        const std::vector<ViewStateKind> &view_states,
        const std::vector<InstanceStateKind> &instance_states);

    QueryCondition create_querycondition(
        const std::vector<SampleRejectedStatusKind> &sample_states,
        const std::vector<ViewStateKind> &view_states,
        const std::vector<InstanceStateKind> &instance_states,
        const std::string &query_expression,
        const std::vector<std::string> &query_parameters);

    ReturnCode_t delete_readcondition(
        ReadCondition *condition);

    ReturnCode_t get_liveliness_changed_status(
        LivelinessChangedStatus &status);

    ReturnCode_t get_requested_deadline_missed_status(
        RequestedDeadlineMissedStatus &status);

    ReturnCode_t get_requested_incompatible_qos_status(
        RequestedIncompatibleQosStatus &status);

    ReturnCode_t get_sample_lost_status(
        SampleLostStatus &status);

    ReturnCode_t get_sample_rejected_status(
        SampleRejectedStatus &status);

    ReturnCode_t get_subscription_matched_status(
        SubscriptionMatchedStatus &status);

    TopicDescription* get_topicdescription();

    Subscriber* get_subscriber();

    ReturnCode_t delete_contained_entities();

    ReturnCode_t wait_for_historical_data(
        const Duration_t &max_wait);

    ReturnCode_t get_matched_publication_data(
        PublicationBuiltinTopicData& publication_data,
        InstanceHandle_t publication_handle);

    ReturnCode_t get_matched_publications(
        const std::vector<InstanceHandle_t>& publication_handles);

private:
    class Impl;
    Impl* impl_;
};
}
}