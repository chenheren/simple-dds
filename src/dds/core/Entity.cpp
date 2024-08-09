#include <simple_dds/dds/core/Entity.h>

namespace simple_dds
{
namespace dds
{
Entity::Entity()
{

}

ReturnCode_t Entity::set_qos(const std::vector<QosPolicy>& qos_list)
{
    return ReturnCode_t::OK;
}

ReturnCode_t Entity::get_qos(std::vector<QosPolicy>& qos_list)
{
    return ReturnCode_t::OK;
}

ReturnCode_t Entity::set_listener(Listener* listener, const std::vector<Status>& mask)
{
    return ReturnCode_t::OK;
}

Listener* Entity::get_listener()
{
    return nullptr;
}

StatusCondition Entity::get_statuscondition()
{

}

std::vector<Status> Entity::get_status_changes()
{

}

ReturnCode_t Entity::enable()
{

}

std::shared_ptr<Entity> Entity::get_instance_handle()
{

}
}
}