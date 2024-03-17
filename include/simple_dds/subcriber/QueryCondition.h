#pragma once

#include <string>
#include <vector>
#include <simple_dds/common/Type.h>

namespace simple_dds
{
class QueryCondition
{
public:
    std::string get_query_expression();

    ReturnCode_t get_query_parameters(std::vector<std::string>& parameters);

    ReturnCode_t set_query_parameters(const std::vector<std::string>& parameters);
};
}