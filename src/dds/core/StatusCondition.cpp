#include <simple_dds/dds/core/StatusCondition.h>

namespace simple_dds
{
namespace dds
{
bool StatusCondition::get_trigger_value()
{
    return false;
}

ReturnCode_t StatusCondition::set_enabled_statuses(
    const std::vector<Status*>& mask)
{

}

std::vector<Status*> StatusCondition::get_enabled_statuses()
{

}


Entity * StatusCondition::get_entity()
{
    return nullptr;
}
}
}