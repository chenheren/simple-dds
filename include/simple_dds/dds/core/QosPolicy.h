#pragma once

#include <string>

namespace simple_dds
{
namespace dds
{
/**
 * This class is the abstract root for all the QoS policies.
 * It provides the basic mechanism for an application to specify quality of service parameters.
 * It has an attribute name that is used to identify uniquely each QoS policy.
 * All concrete QosPolicy classes derive from this root and include a value whose type depends on the concrete QoS policy
 */
class QosPolicy
{
public:
    std::string name;
};
}
}