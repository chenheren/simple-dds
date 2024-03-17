#pragma once

#include <string>
#include <simple_dds/common/Type.h>
#include <simple_dds/topic/Topic.h>
#include <simple_dds/topic/TopicDescription.h>

namespace simple_dds
{
/**
 * MultiTopic is a specialization of TopicDescription that allows subscriptions to
 * combine/filter/rearrange data coming from several topics
 */
class MultiTopic
{
public:
    /**
     * This operation returns the expression_parameters associated with the MultiTopic.
     * That is, the parameters specified on the last successful call to set_expression_parameters,
     * or if set_expression_parameters was never called, the parameters specified when the MultiTopic was created.
     * @param expression_parameters
     * @return
     */
    ReturnCode_t get_expression_parameters(std::vector<std::string>& expression_parameters);

    /**
     * This operation changes the expression_parameters associated with the MultiTopic.
     * @param expression_parameters
     * @return
     */
    ReturnCode_t set_expression_parameters(const std::vector<std::string>& expression_parameters);

private:
    /**
     * The subscription_expression associated with the MultiTopic.
     * That is, the expression specified when the MultiTopic was created.
     */
    std::string subscription_expression_;
};
}