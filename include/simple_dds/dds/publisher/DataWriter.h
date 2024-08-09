#pragma once

#include <vector>
#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Entity.h>
#include <simple_dds/dds/core/Status.h>
#include <simple_dds/dds/core/Listener.h>
#include <simple_dds/dds/core/QosPolicy.h>

namespace simple_dds
{
namespace dds
{
class Topic;
class Publisher;

class DataWriter: public Entity
{
public:
    InstanceHandle_t register_instance(
        void* instance);

    InstanceHandle_t register_instance_w_timestamp(
        void* instance,
        Time_t timestamp);

    ReturnCode_t unregister_instance(
        void* instance,
        InstanceHandle_t handle);

    InstanceHandle_t unregister_instance_w_timestamp(
        void* instance,
        InstanceHandle_t handle,
        Time_t timestamp);

    ReturnCode_t get_key_value(
        void* instance,
        InstanceHandle_t handle);

    InstanceHandle_t lookup_instance(
        void* instance);

    ReturnCode_t write(
        void* data,
        InstanceHandle_t handle);

    ReturnCode_t write_w_timestamp(
        void* data,
        InstanceHandle_t handle,
        Time_t timestamp);

    ReturnCode_t dispose(
        void* data,
        InstanceHandle_t handle);

    ReturnCode_t dispose_w_timestamp(
        void* data,
        InstanceHandle_t handle,
        Time_t timestamp);

    ReturnCode_t wait_for_acknowledgments(
        Duration_t max_wait);

    ReturnCode_t get_liveliness_lost_status(
        LivelinessLostStatus& status);

    ReturnCode_t get_offered_deadline_missed_status(
        OfferedDeadlineMissedStatus& status);

    ReturnCode_t get_offered_incompatible_qos_status(
        OfferedIncompatibleQosStatus& status);

    ReturnCode_t get_publication_matched_status(
        PublicationMatchedStatus& status);

    Topic* get_topic();

    Publisher* get_publisher();

    ReturnCode_t assert_liveliness();

    ReturnCode_t get_matched_subscription_data(
        SubscriptionBuiltinTopicData& subscription_data,
        InstanceHandle_t subscription_handle);

    ReturnCode_t get_matched_subscriptions(
        std::vector<InstanceHandle_t>& subscription_handles);
};
}
}