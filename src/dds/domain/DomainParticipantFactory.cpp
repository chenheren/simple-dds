#include <simple_dds/dds/domain/DomainParticipantFactory.h>

namespace simple_dds
{
namespace dds
{
DomainParticipant *DomainParticipantFactory::create_participant(
    DomainId_t domain_id,
    const DomainParticipantQos &qos,
    DomainParticipantListener *listener,
    const StatusKinds &status_Kinds)
{

}

ReturnCode_t DomainParticipantFactory::delete_participant(
    DomainParticipant *participant)
{

}

DomainId_t DomainParticipantFactory::lookup_participant(
    DomainParticipant* participant)
{

}

ReturnCode_t DomainParticipantFactory::set_default_participant_qos(
    const std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipantFactory::get_default_participant_qos(
    std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipantFactory::get_qos(
    std::vector<QosPolicy>& qos_list)
{

}
}
}
