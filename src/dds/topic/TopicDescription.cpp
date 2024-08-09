#include <simple_dds/dds/topic/TopicDescription.h>

namespace simple_dds
{
namespace dds
{
DomainParticipant *TopicDescription::get_participant()
{
    return participant_;
}

const std::string& TopicDescription::get_type_name() const
{
    return type_name_;
}

const std::string& TopicDescription::get_name() const
{
    return name_;
}
}
}