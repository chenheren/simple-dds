#pragma once

#include <string>
#include <simple_dds/common/Type.h>

namespace simple_dds
{
class Status
{
public:

};

class InconsistentTopicStatus
{
public:
    std::int16_t total_count;
    std::int16_t total_count_change;
};

class LivelinessLostStatus
{
public:
    std::int32_t total_count;
    std::int32_t total_count_change;
};

class OfferedDeadlineMissedStatus
{
public:
    long total_count;
    long total_count_change;
    InstanceHandle_t last_instance_handle;
};

class SampleLostStatus
{
public:
    long total_count;
    long total_count_change;
};

enum class SampleRejectedStatusKind: std::uint8_t
{
    NOT_REJECTED,
    REJECTED_BY_INSTANCES_LIMIT,
    REJECTED_BY_SAMPLES_LIMIT,
    REJECTED_BY_SAMPLES_PER_INSTANCE_LIMIT
};

class SampleRejectedStatus
{
public:
    long total_count;
    long total_count_change;
    SampleRejectedStatusKind last_reason;
    InstanceHandle_t last_instance_handle;
};

class LivelinessChangedStatus
{
    long alive_count;
    long not_alive_count;
    long alive_count_change;
    long not_alive_count_change;
    InstanceHandle_t last_publication_handle;
};

struct RequestedDeadlineMissedStatus
{
    long total_count;
    long total_count_change;
    InstanceHandle_t last_instance_handle;
};

using QosPolicyId_t = std::int32_t;

struct QosPolicyCount
{
    QosPolicyId_t policy_id;
    long count;
};

using QosPolicyCountSeq = std::vector<QosPolicyCount> ;

struct RequestedIncompatibleQosStatus
{
    long total_count;
    long total_count_change;
    QosPolicyId_t last_policy_id;
    QosPolicyCountSeq policies;
};

struct PublicationMatchedStatus
{
    long total_count;
    long total_count_change;
    long current_count;
    long current_count_change;
    InstanceHandle_t last_subscription_handle;
};

struct SubscriptionMatchedStatus
{
    long total_count;
    long total_count_change;
    long current_count;
    long current_count_change;
    InstanceHandle_t last_publication_handle;
};


}