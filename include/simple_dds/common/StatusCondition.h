#pragma once

#include <vector>
#include <simple_dds/common/Type.h>

namespace simple_dds
{
class StatusCondition
{
public:
    ReturnCode_t set_enable_statuses(const std::vector<Status> mask);

    std::vector<Status> get_enable_statuses();

    Entity* get_entity();
};
}