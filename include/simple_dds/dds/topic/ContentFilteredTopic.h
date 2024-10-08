#pragma once

#include <string>
#include <simple_dds/dds/core//Type.h>
#include <simple_dds/dds/topic/Topic.h>

namespace simple_dds
{
namespace dds
{
/**
 * ContentFilteredTopic is a specialization of TopicDescription that allows for content-based subscriptions
 */
class ContentFilteredTopic
{
public:
    /**
     * This operation returns the Topic associated with the ContentFilteredTopic.
     * That is, the Topic specified when the ContentFilteredTopic was created.
     * @return
     */
    Topic *get_related_topic();

    ReturnCode_t get_expression_parameters(std::vector<std::string> &expression_parameters);

    ReturnCode_t set_expression_parameters(const std::vector<std::string> &expression_parameters);

private:
    std::string filter_expression_;
};
}
}