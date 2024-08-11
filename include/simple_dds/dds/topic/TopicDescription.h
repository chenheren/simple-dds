#pragma once

#include <string>
#include <simple_dds/dds/core/Type.h>

namespace simple_dds
{
namespace dds
{
class DomainParticipant;

/**
 * This class is an abstract class. It is the base class for Topic, ContentFilteredTopic, and MultiTopic
 */
class TopicDescription
{
public:
    TopicDescription();

    TopicDescription(
        std::string name,
        std::string type_name,
        DomainParticipant *participant);

    virtual ~TopicDescription() = default;

    /**
     * This operation returns the DomainParticipant to which the TopicDescription belongs.
     * @return
     */
    DomainParticipant *get_participant();

    /**
     * The type_name used to create the TopicDescription.
     * @return
     */
    const std::string& get_type_name() const;

    /**
     * The name used to create the TopicDescription.
     * @return
     */
    const std::string& get_name() const;

private:
    std::string name_;
    std::string type_name_;
    DomainParticipant *participant_;
};
}
}