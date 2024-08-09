#pragma once

#include <memory>
#include <vector>
#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Listener.h>
#include <simple_dds/dds/core/QosPolicy.h>
#include <simple_dds/dds/core/Status.h>
#include <simple_dds/dds/core/StatusCondition.h>

namespace simple_dds
{
namespace dds
{
class Entity
{
public:
    Entity();

    virtual ~Entity() = default;

    virtual ReturnCode_t set_qos(const std::vector<QosPolicy>& qos_list);

    virtual ReturnCode_t get_qos(std::vector<QosPolicy>& qos_list);

    virtual ReturnCode_t set_listener(Listener* listener, const std::vector<Status>& mask);

    virtual Listener* get_listener();

    StatusCondition get_statuscondition() ;

    std::vector<Status> get_status_changes() ;

    ReturnCode_t enable() ;

    std::shared_ptr<Entity> get_instance_handle() ;
};
}
}