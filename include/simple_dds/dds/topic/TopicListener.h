#pragma once

#include <string>
#include <simple_dds/dds/core/Status.h>

namespace simple_dds
{
namespace dds
{
class Topic;

/**
 * Since Topic is a kind of Entity, it has the ability to have an associated listener.
 * In this case, the associated listener should be of concrete type TopicListener.
 */
class TopicListener
{
public:

    virtual ~TopicListener() = default;

    virtual void on_inconsistent_topic(const Topic* topic, const InconsistentTopicStatus& status) {};

};
}
}