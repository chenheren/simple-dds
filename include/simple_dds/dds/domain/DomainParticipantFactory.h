#pragma once

#include <memory>
#include <vector>
#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/StatusKinds.h>
#include <simple_dds/dds/domain/DomainParticipantQos.h>
#include <simple_dds/dds/domain/DomainParticipantListener.h>

namespace simple_dds
{
namespace dds
{
class DomainParticipant;

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

    /**
     * This operation deletes an existing DomainParticipant.
     * This operation can only be invoked if all domain entities belonging to the participant have already been deleted.
     * Otherwise the error PRECONDITION_NOT_MET is returned.
     * Possible error codes returned in addition to the standard ones: PRECONDITION_NOT_MET.
     * @param participant
     * @return
     */
    ReturnCode_t delete_participant(
        DomainParticipant *participant);

    /**
     * This operation retrieves a previously created DomainParticipant belonging to specified domain_id.
     * If no such DomainParticipant exists, the operation will return nullptr.
     * If multiple DomainParticipant entities belonging to that domain_id exist,
     * then the operation will return one of them. It is not specified which one.
     * @param participant
     * @return then participant found, if not found return nullptr.
     */
    DomainParticipant* lookup_participant(
        DomainId_t);

    /**
     * This operation sets a default value of the DomainParticipant QoS policies which will be used for newly created
     * DomainParticipant entities in the case where the QoS policies are defaulted in the create_participant operation.
     * This operation will check that the resulting policies are self consistent;
     * if they are not, the operation will have no effect and return INCONSISTENT_POLICY
     * @param qos_list
     * @return
     */
    ReturnCode_t set_default_participant_qos(
        const std::vector<QosPolicy>& qos_list);

    /**
     * This operation retrieves the default value of the DomainParticipant QoS, that is,
     * the QoS policies which will be used for newly created DomainParticipant entities
     * in the case where the QoS policies are defaulted in the create_participant operation.
     * @param qos_list
     * @return
     */
    ReturnCode_t get_default_participant_qos(
        std::vector<QosPolicy>& qos_list);

    /**
     * This operation sets the value of the DomainParticipantFactory QoS policies.
     * These policies control the behavior of the object a factory for entities
     * @param qos_list
     * @return
     */
    ReturnCode_t get_qos(
        std::vector<QosPolicy>& qos_list);

    /**
     * This operation returns the value of the DomainParticipantFactory QoS policies
     * @param qos_list
     * @return
     */
    ReturnCode_t set_qos(
        const std::vector<QosPolicy>& qos_list);

private:
    class Impl;
    Impl* impl_;
};
}
}

