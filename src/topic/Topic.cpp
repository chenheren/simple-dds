#include <simple_dds/topic/Topic.h>

namespace simple_dds
{
ReturnCode_t Topic::set_qos(const std::vector<QosPolicy> &qos_list)
{
    return ReturnCode_t::NOT_ENABLE;
}

ReturnCode_t Topic::get_qos(std::vector<QosPolicy> &qos_list)
{
    return ReturnCode_t::NOT_ENABLE;

}

ReturnCode_t Topic::set_listener(Listener *listener, const std::vector<Status> &mask)
{
    return ReturnCode_t::NOT_ENABLE;
}

Listener * Topic::get_listener()
{
    return nullptr;
}

ReturnCode_t Topic::enable()
{
    return ReturnCode_t::NOT_ENABLE;

}

ReturnCode_t Topic::get_inconsistent_topic_status(InconsistentTopicStatus& status)
{

}
}