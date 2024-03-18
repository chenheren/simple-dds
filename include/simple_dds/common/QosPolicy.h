#pragma once

#include <string>

namespace simple_dds
{
/**
 * This class is the abstract root for all the QoS policies.
 */
class QosPolicy
{
public:
    std::string name;
};
}