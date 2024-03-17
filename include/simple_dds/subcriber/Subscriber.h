#pragma once

#include <simple_dds/common/Type.h>
#include <simple_dds/common/Entity.h>s
#include <simple_dds/domain/DomainParticipant.h>

namespace simple_dds
{
class Subscriber: public Entity
{
public:
    DataReader create_datareader();

    ReturnCode_t delete_datareader();

    DataReader lookup_datareader();

    ReturnCode_t begin_access();

    ReturnCode_t end_access();

    ReturnCode_t get_datareader();

    ReturnCode_t notify_datareader();

    DomainParticipant& get_participant();

    ReturnCode_t delete_contained_entities();

    ReturnCode_t set_default_datareader_qos(const std::vector<QosPolicy>& qos);

    ReturnCode_t get_default_datareader_qos(std::vector<QosPolicy>& qos);

    ReturnCode_t copy_from_topic_qos(std::vector<QosPolicy>& qos);


};
}