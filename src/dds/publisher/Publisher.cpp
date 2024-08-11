#include <simple_dds/dds/publisher/Publisher.h>

namespace simple_dds
{
namespace dds
{
class Publisher::Impl
{
public:

};

DataWriter* Publisher::create_datawriter(
    Topic* topic,
    const std::vector<QosPolicy>& qos,
    DataWriterListener* listener,
    const std::vector<Status>& mask)
{

}

ReturnCode_t Publisher::delete_datawriter(
    DataWriter& writer)
{

}

DataWriter* Publisher::lookup_datawriter(
    const std::string& topic_name)
{

}

ReturnCode_t Publisher::suspend_publications()
{

}

ReturnCode_t Publisher::resume_publications()
{

}

ReturnCode_t Publisher::begin_coherent_changes()
{

}

ReturnCode_t Publisher::end_coherent_changes()
{

}

ReturnCode_t Publisher::wait_for_acknowledgments(
    const Duration_t& max_wait)
{

}

DomainParticipant* Publisher::get_participant()
{

}

ReturnCode_t Publisher::delete_contained_entities()
{

}

ReturnCode_t Publisher::set_default_datawriter_qos(
    const std::vector<QosPolicy>& qos_list)
{

}

std::vector<QosPolicy> Publisher::get_default_datawriter_qos()
{

}

ReturnCode_t Publisher::copy_from_topic_qos(
    std::vector<QosPolicy>& datawriter_qos,
    const std::vector<QosPolicy>& topic_qos)
{

}
}
}
