#pragma once

#include <string>
#include <simple_dds/common/Type.h>
#include <simple_dds/common/Entity.h>
#include <simple_dds/common/Status.h>
#include <simple_dds/topic/TopicDescription.h>

namespace simple_dds
{
/**
 * Topic is the most basic description of the data to be published and subscribed.
 */
class Topic: public Entity, public TopicDescription
{
public:
    ReturnCode_t set_qos(const std::vector<QosPolicy> &qos_list) override;

    ReturnCode_t get_qos(std::vector<QosPolicy> &qos_list) override;

    ReturnCode_t set_listener(Listener *listener, const std::vector<Status> &mask) override;

    Listener * get_listener() override;

    ReturnCode_t enable() override;

    ReturnCode_t get_inconsistent_topic_status(InconsistentTopicStatus& status);
};
}