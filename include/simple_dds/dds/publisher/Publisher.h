#pragma once

#include <vector>
#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Status.h>
#include <simple_dds/dds/topic/Topic.h>
#include <simple_dds/dds/publisher/DataWriter.h>
#include <simple_dds/dds/publisher/DataWriterListener.h>

namespace simple_dds
{
namespace dds
{
class Publisher
{
public:
    DataWriter* create_datawriter(
        Topic* topic,
        const std::vector<QosPolicy>& qos,
        DataWriterListener* listener,
        const std::vector<Status>& mask);
};
}
}