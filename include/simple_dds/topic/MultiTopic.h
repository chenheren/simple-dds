#pragma once

#include <string>
#include <simple_dds/common/Type.h>
#include <simple_dds/topic/Topic.h>
#include <simple_dds/topic/TopicDescription.h>

namespace simple_dds
{

class MultiTopic
{
public:
    ReturnCode_t get_expression_parameters(std::vector<std::string>& expression_parameters);

    ReturnCode_t set_expression_parameters(const std::vector<std::string>& expression_parameters);

private:
    std::string subscription_expression_;
};
}