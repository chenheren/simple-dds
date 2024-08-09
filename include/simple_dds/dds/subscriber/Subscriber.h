#pragma once

#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Entity.h>
#include <simple_dds/dds/core/StatusKinds.h>
#include <simple_dds/dds/topic/TopicDescription.h>
#include <simple_dds/dds/subscriber/DataReader.h>
#include <simple_dds/dds/subscriber/DataReaderListener.h>

namespace simple_dds
{
namespace dds
{
class DomainParticipant;

class Subscriber: public Entity
{
public:
    DataReader* create_datareader(
        const TopicDescription* topic_description,
        const std::vector<QosPolicy>& qos_list,
        DataReaderListener* listener,
        const StatusKinds& status = StatusKinds::all());

    ReturnCode_t delete_datareader(
        DataReader* data_reader);

    DataReader lookup_datareader(
        const std::string& topic_name);

    ReturnCode_t begin_access();

    ReturnCode_t end_access();

    ReturnCode_t get_datareader(
        std::vector<DataReader*>& readers,
        const std::vector<SampleStateKind>& sample_states,
        const std::vector<ViewStateKind>& view_states,
        const std::vector<InstanceStateKind>& instance_states);

    ReturnCode_t notify_datareader();

    DomainParticipant* get_participant();

    ReturnCode_t delete_contained_entities();

    ReturnCode_t set_default_datareader_qos(
        const std::vector<QosPolicy> &qos);

    ReturnCode_t get_default_datareader_qos(
        std::vector<QosPolicy> &qos);

    ReturnCode_t copy_from_topic_qos(
        std::vector<QosPolicy>& datareader_qos,
        const std::vector<QosPolicy>& topic_qos);

};
}
}