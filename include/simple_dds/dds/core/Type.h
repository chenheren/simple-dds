#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace simple_dds
{
namespace dds
{
enum class ReturnCode_t: std::uint8_t
{
    /**
     * Successful return
     */
    OK,
    /**
     * Generic, unspecified error.
     */
    ERROR,
    /**
     * Illegal parameter value.
     */
    BAD_PARAMETER,
    /**
     * Unsupported operation. Can only be returned by operations that are optional.
     */
    UNSUPPORTED,
    /**
     * The object target of this operation has already been deleted.
     */
    ALREADY_DEFINED,
    /**
     * Service ran out of the resources needed to complete the operation.
     */
    OUT_OF_RESOURCE,
    /**
     * Operation invoked on an Entity that is not yet enabled.
     */
    NOT_ENABLE,
    /**
     * Application attempted to modify an immutable QosPolicy.
     */
    IMMUTABLE_POLICY,
    /**
     * Application specified a set of policies that are not consistent with each other.
     */
    INCONSISTENT_POLICY,
    /**
     * A pre-condition for the operation was not met.
     */
    PRECONDITION_NOT_MET,
    /**
     * The operation timed out.
     */
    TIMEOUT,
    /**
     * An operation was invoked on an inappropriate object or at an inappropriate time (
     * as determined by policies set by the specification or the Service implementation).
     * There is no precondition that could be changed to make the operation succeed.
     */
    ILLEGAL_OPERATION,
    /**
     * Indicates a transient situation where the operation did not return any data but there is no inherent error.
     */
    NO_DATA
};

using octet = std::uint8_t;

using DomainId_t = std::uint32_t;

using InstanceHandle_t = std::int32_t;

using InstanceStateKind = std::int32_t;

using ViewStateKind = std::int32_t;

using SampleStateKind = std::int32_t;

struct Time_t
{
    std::uint32_t sec;
    std::uint32_t nanosec;
};

struct Duration_t
{
    std::uint32_t sec;
    std::uint32_t nanosec;
};

struct BuiltinTopicKey_t
{
    std::uint64_t value[3]{};
};

struct UserDataQosPolicy
{
    std::vector<std::uint8_t> value;
};

struct ParticipantBuiltinTopicData
{
    BuiltinTopicKey_t key;
    UserDataQosPolicy user_data;
};

enum class DurabilityQosPolicyKind
{
    VOLATILE_DURABILITY_QOS,
    TRANSIENT_LOCAL_DURABILITY_QOS,
    TRANSIENT_DURABILITY_QOS,
    PERSISTENT_DURABILITY_QOS
};

struct DurabilityQosPolicy
{
    DurabilityQosPolicyKind kind;
};

enum class HistoryQosPolicyKind
{
    KEEP_LAST_HISTORY_QOS,
    KEEP_ALL_HISTORY_QOS
};

struct DurabilityServiceQosPolicy
{
    Duration_t            service_cleanup_delay;
    HistoryQosPolicyKind  history_kind;
    std::uint32_t         history_depth;
    std::uint32_t         max_samples;
    std::uint32_t         max_instances;
    std::uint32_t         max_samples_per_instance;

};

struct DeadlineQosPolicy
{
    Duration_t period;
};

struct LatencyBudgetQosPolicy
{
    Duration_t duration;
};

enum class LivelinessQosPolicyKind
{
    AUTOMATIC_LIVELINESS_QOS,
    MANUAL_BY_PARTICIPANT_LIVELINESS_QOS,
    MANUAL_BY_TOPIC_LIVELINESS_QOS
};

struct LivelinessQosPolicy
{
    LivelinessQosPolicyKind kind;
    Duration_t lease_duration;
};

enum class ReliabilityQosPolicyKind
{
    BEST_EFFORT_RELIABILITY_QOS,
    RELIABLE_RELIABILITY_QOS
};

struct ReliabilityQosPolicy
{
    ReliabilityQosPolicyKind kind;
    Duration_t max_blocking_time;
};

struct TransportPriorityQosPolicy
{
    std::int32_t value;
};

struct LifespanQosPolicy
{
    Duration_t duration;
};

enum class DestinationOrderQosPolicyKind
{
    BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS,
    BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS
};

struct DestinationOrderQosPolicy
{
    DestinationOrderQosPolicyKind kind;
};

struct HistoryQosPolicy
{
    HistoryQosPolicyKind kind;
    std::uint32_t depth;
};

enum class OwnershipQosPolicyKind
{
    SHARED_OWNERSHIP_QOS,
    EXCLUSIVE_OWNERSHIP_QOS
};

struct ResourceLimitsQosPolicy
{
    std::uint32_t max_samples;
    std::uint32_t max_instances;
    std::uint32_t max_samples_per_instance;
};

struct OwnershipQosPolicy
{
    OwnershipQosPolicyKind kind;
};

struct TopicDataQosPolicy
{
    std::vector<std::int8_t> value;
};

struct TopicBuiltinTopicData
{
    BuiltinTopicKey_t           key;
    std::string                 name;
    std::string                 type_name;
    DurabilityQosPolicy         durability;
    DurabilityServiceQosPolicy  durability_service;
    DeadlineQosPolicy           deadline;
    LatencyBudgetQosPolicy      latency_budget;
    LivelinessQosPolicy         liveliness;
    ReliabilityQosPolicy        reliability;
    TransportPriorityQosPolicy  transport_priority;
    LifespanQosPolicy           lifespan;
    DestinationOrderQosPolicy   destination_order;
    HistoryQosPolicy            history;
    ResourceLimitsQosPolicy     resource_limits;
    OwnershipQosPolicy          ownership;
    TopicDataQosPolicy          topic_data;
};

using QosPolicyId_t = std::int32_t;

struct QosPolicyCount
{
    QosPolicyId_t policy_id;
    std::int32_t  count;
};

using QosPolicyCountSeq = std::vector<QosPolicyCount>;

struct OfferedIncompatibleQosStatus
{
    std::uint32_t     total_count;
    std::uint32_t     total_count_change;
    QosPolicyId_t     last_policy_id;
    QosPolicyCountSeq policies;
};

struct TimeBasedFilterQosPolicy
{
    Duration_t minimum_separation;
};

enum class PresentationQosPolicyAccessScopeKind
{
    INSTANCE_PRESENTATION_QOS,
    TOPIC_PRESENTATION_QOS,
    GROUP_PRESENTATION_QOS
};

struct PresentationQosPolicy
{
    PresentationQosPolicyAccessScopeKind access_scope;
    bool coherent_access;
    bool ordered_access;
};

struct PartitionQosPolicy
{
    std::vector<std::string> name;
};

struct GroupDataQosPolicy
{
    std::vector<std::int8_t> value;
};

struct SubscriptionBuiltinTopicData
{
    BuiltinTopicKey_t          key;
    BuiltinTopicKey_t          participant_key;
    std::string                topic_name;
    std::string                type_name;
    DurabilityQosPolicy        durability;
    DeadlineQosPolicy          deadline;
    LatencyBudgetQosPolicy     latency_budget;
    LivelinessQosPolicy        liveliness;
    ReliabilityQosPolicy       reliability;
    OwnershipQosPolicy         ownership;
    DestinationOrderQosPolicy  destination_order;
    UserDataQosPolicy          user_data;
    TimeBasedFilterQosPolicy   time_based_filter;
    PresentationQosPolicy      presentation;
    PartitionQosPolicy         partition;
    TopicDataQosPolicy         topic_data;
    GroupDataQosPolicy         group_data;
};

struct OwnershipStrengthQosPolicy
{
    std::int32_t value;
};

struct PublicationBuiltinTopicData
{
    BuiltinTopicKey_t          key;
    BuiltinTopicKey_t          participant_key;
    std::string                topic_name;
    std::string                type_name;
    DurabilityQosPolicy        durability;
    DurabilityServiceQosPolicy durability_service;
    DeadlineQosPolicy          deadline;
    LatencyBudgetQosPolicy     latency_budget;
    LivelinessQosPolicy        liveliness;
    ReliabilityQosPolicy       reliability;
    LifespanQosPolicy          lifespan;
    UserDataQosPolicy          user_data;
    OwnershipQosPolicy         ownership;
    OwnershipStrengthQosPolicy ownership_strength;
    DestinationOrderQosPolicy  destination_order;
    PresentationQosPolicy      presentation;
    PartitionQosPolicy         partition;
    TopicDataQosPolicy         topic_data;
    GroupDataQosPolicy         group_data;
};
}
}