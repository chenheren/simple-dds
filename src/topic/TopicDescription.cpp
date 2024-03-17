#include <simple_dds/topic/TopicDescription.h>

namespace simple_dds
{
DomainParticipant* TopicDescription::get_participant()
{
    return participant_;
}

std::string TopicDescription::get_type_name()
{
    return type_name_;
}

std::string TopicDescription::get_name()
{
    return name_;
}
}