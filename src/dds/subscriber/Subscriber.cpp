#include <simple_dds/dds/subscriber/Subscriber.h>

namespace simple_dds
{
namespace dds
{
DataReader* Subscriber::create_datareader(
    const TopicDescription* topic_description,
    const std::vector<QosPolicy>& qos_list,
    DataReaderListener* listener,
    const StatusKinds& status)
{

}

ReturnCode_t Subscriber::delete_datareader(
    DataReader* data_reader)
{

}

DataReader Subscriber::lookup_datareader(
    const std::string& topic_name)
{

}

ReturnCode_t Subscriber::begin_access()
{

}

ReturnCode_t Subscriber::end_access()
{

}

ReturnCode_t Subscriber::get_datareader(
    std::vector<DataReader*>& readers,
    const std::vector<SampleStateKind>& sample_states,
    const std::vector<ViewStateKind>& view_states,
    const std::vector<InstanceStateKind>& instance_states)
{

}

ReturnCode_t Subscriber::notify_datareader()
{

}

DomainParticipant* Subscriber::get_participant()
{

}

ReturnCode_t Subscriber::delete_contained_entities()
{

}

ReturnCode_t Subscriber::set_default_datareader_qos(
    const std::vector<QosPolicy> &qos)
{

}

ReturnCode_t Subscriber::get_default_datareader_qos(
    std::vector<QosPolicy> &qos)
{

}

ReturnCode_t Subscriber::copy_from_topic_qos(
    std::vector<QosPolicy>& datareader_qos,
    const std::vector<QosPolicy>& topic_qos)
{

}
}
}
