#pragma once

#include <string>
#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Entity.h>
#include <simple_dds/dds/core/Status.h>
#include <simple_dds/dds/topic/TopicDescription.h>

namespace simple_dds
{
namespace dds
{
/**
 * Topic is the most basic description of the data to be published and subscribed.
 */
class Topic: public Entity, public TopicDescription
{
public:

    ReturnCode_t get_inconsistent_topic_status(
        InconsistentTopicStatus &status);
};
}
}