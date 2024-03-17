#pragma once

#include <string>
#include <simple_dds/common/Type.h>
#include <simple_dds/domain/DomainParticipant.h>

namespace simple_dds
{
/**
 * This class is an abstract class. It is the base class for Topic, ContentFilteredTopic, and MultiTopic
 */
class TopicDescription
{
public:
    /**
     * This operation returns the DomainParticipant to which the TopicDescription belongs.
     * @return
     */
    DomainParticipant* get_participant();

    /**
     * The type_name used to create the TopicDescription.
     * @return
     */
    std::string get_type_name();

    /**
     * The name used to create the TopicDescription.
     * @return
     */
    std::string get_name();

private:
    std::string name_;
    std::string type_name_;
    DomainParticipant* participant_;
};
}