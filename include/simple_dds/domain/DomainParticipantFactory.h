#pragma once

#include <memory>
#include <vector>
#include <simple_dds/common/Type.h>
#include <simple_dds/domain/DomainParticipant.h>

namespace simple_dds
{
class DomainParticipantFactory
{
public:
    static DomainParticipantFactory& GetInstance()
    {

    }

    std::shared_ptr<Participant> create_participant(DomainId_t domain_id,
                                                    const std::vector<QosPolicy>& qos_list,
                                                    );

    std::shared_ptr<Participant> lookup_participant();

};
}

