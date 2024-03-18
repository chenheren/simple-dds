#pragma once

#include <memory>
#include <vector>
#include <simple_dds/common/Type.h>
#include <simple_dds/domain/DomainParticipant.h>
#include <simple_dds/domain/DomainParticipantListener.h>

namespace simple_dds
{
/**
 * The sole purpose of this class is to allow the creation and destruction of DomainParticipant objects
 */
class DomainParticipantFactory
{
public:
    static DomainParticipantFactory& get_instance()
    {
        static DomainParticipantFactory instance;
        return instance;
    }

    std::shared_ptr<DomainParticipant> create_participant(
        DomainId_t domain_id,
        const std::vector<QosPolicy>& qos_list = {},
        DomainParticipantListener* listener = nullptr);

    ReturnCode_t delete_participant(DomainParticipant* participant);

    std::shared_ptr<DomainParticipant> lookup_participant();

    ReturnCode_t set_default_participant_qos();

    ReturnCode_t get_default_participant_qos();

    ReturnCode_t get_qos();

};
}

