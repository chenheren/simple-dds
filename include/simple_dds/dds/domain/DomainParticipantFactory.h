#pragma once

#include <memory>
#include <vector>
#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/StatusKinds.h>
#include <simple_dds/dds/domain/DomainParticipant.h>
#include <simple_dds/dds/domain/DomainParticipantQos.h>
#include <simple_dds/dds/domain/DomainParticipantListener.h>

namespace simple_dds
{
namespace dds
{
/**
 * The sole purpose of this class is to allow the creation and destruction of DomainParticipant objects
 */
class DomainParticipantFactory
{
public:
    /**
     * This operation returns the DomainParticipantFactory singleton.
     * The operation is idempotent, that is, it can be called multiple times without side-effects
     * and it will return the same DomainParticipantFactory instance
     * @return
     */
    static DomainParticipantFactory &get_instance()
    {
        static DomainParticipantFactory instance;
        return instance;
    }

    /**
     * This operation creates a new DomainParticipant object.
     * The DomainParticipant signifies that the calling application intends to join the Domain identified by the domain_id argument
     * @param domain_id
     * @param qos
     * @param listener
     * @param statusMask
     * @return In case of failure, the operation will return nullptr
     */
    DomainParticipant* create_participant(
        DomainId_t domain_id,
        const DomainParticipantQos &qos,
        DomainParticipantListener *listener = nullptr,
        const StatusKinds &statusMask = StatusKinds::all()
    );

    ReturnCode_t delete_participant(
        DomainParticipant *participant);

    DomainId_t lookup_participant(
        DomainParticipant* participant);

    ReturnCode_t set_default_participant_qos(
        const std::vector<QosPolicy>& qos_list);

    ReturnCode_t get_default_participant_qos(
        std::vector<QosPolicy>& qos_list);

    ReturnCode_t get_qos(
        std::vector<QosPolicy>& qos_list);

};
}
}

