#pragma once

#include <simple_dds/core/base/Type.h>
#include <simple_dds/core/base/Entity.h>
#include <simple_dds/publisher/Publisher.h>
#include <simple_dds/domain/DomainParticipantQos.h>

namespace simple_dds
{
class DomainParticipant: public Entity
{
public:
    ReturnCode_t set_qos(const DomainParticipantQos& qos) override;

    ReturnCode_t set_qos(std::vector<QosPolicy>& qos_list) override;

    ReturnCode_t set_listener(Listener* listener, const std::vector<Status>& mask) override;

    Listener* get_listener() override;

    StatusCondition get_statuscondition() override;

    std::vector<Status> get_status_changes() override;

    ReturnCode_t enable() override;

    std::shared_ptr<Entity> get_instance_handle() override;

    std::shared_ptr<Publisher> create_publisher(std::vector<QosPolicy>& qos_list, );

private:
    class DomainParticipantImpl;
    DomainParticipantImpl* impl_;
};
}