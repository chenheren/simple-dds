#pragma once

#include <string>
#include <simple_dds/topic/Topic.h>
#include <simple_dds/common/Type.h>
#include <simple_dds/common/Status.h>
#include <simple_dds/domain/DomainParticipant.h>

namespace simple_dds
{
/**
 * Since Topic is a kind of Entity, it has the ability to have an associated listener.
 * In this case, the associated listener should be of concrete type TopicListener.
 */
class TopicListener
{
public:

    void on_inconsistent_topic(const Topic& topic, InconsistentTopicStatus status);

};
}