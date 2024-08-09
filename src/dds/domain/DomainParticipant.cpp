#include <mutex>
#include <chrono>
#include <algorithm>
#include <unordered_map>
#include <simple_dds/dds/domain/DomainParticipant.h>

namespace simple_dds
{
namespace dds
{
class DomainParticipant::Impl
{
public:
    std::mutex entity_mutex_;
    std::unordered_map<InstanceHandle_t, Entity*> entities_;

    std::mutex publisher_mutex_;
    std::vector<Publisher*> publishers_;

    std::mutex subscriber_mutex_;
    std::vector<Subscriber*> subscribers_;
};

Publisher* DomainParticipant::create_publisher(
    const std::vector<QosPolicy>& qos_list,
    PublisherListener* listener,
    const std::vector<Status*>& mask)
{
    std::lock_guard<std::mutex> lock(impl_->publisher_mutex_);
    auto ptr = new Publisher();
    impl_->publishers_.push_back(ptr);
    return ptr;
}

ReturnCode_t DomainParticipant::delete_publisher(
    const Publisher* publisher)
{
    std::lock_guard<std::mutex> lock(impl_->publisher_mutex_);
    auto iter = std::find(impl_->publishers_.cbegin(), impl_->publishers_.cend(), publisher);
    if (iter != impl_->publishers_.cend())
    {
        impl_->publishers_.erase(iter);
    }
    return ReturnCode_t::OK;
}

Subscriber* DomainParticipant::create_subscriber(
    const std::vector<QosPolicy>& qos_list,
    SubscriberListener* listener,
    const std::vector<Status*>& mask)
{
    std::lock_guard<std::mutex> lock(impl_->subscriber_mutex_);
    auto ptr = new Subscriber();
    impl_->subscribers_.push_back(ptr);
    return ptr;
}

ReturnCode_t DomainParticipant::delete_subscriber(
    Subscriber* subscriber)
{
    std::lock_guard<std::mutex> lock(impl_->subscriber_mutex_);
    auto iter = std::find(impl_->subscribers_.cbegin(), impl_->subscribers_.cend(), subscriber);
    if (iter != impl_->subscribers_.cend())
    {
        impl_->subscribers_.erase(iter);
    }
    return ReturnCode_t::OK;
}

Topic *DomainParticipant::create_topic(
    const std::string& topic_name,
    const std::string& type_name,
    const std::vector<QosPolicy>& qos_list,
    TopicListener* listener,
    const std::vector<Status*>& mask)
{

}

ReturnCode_t DomainParticipant::delete_topic(
    Topic* topic)
{
    return ReturnCode_t::OK;
}

ContentFilteredTopic DomainParticipant::create_contentfilteredtopic(
    const std::string& name,
    Topic* related_topic,
    const std::string& filter_expression,
    const std::vector<std::string>& expression_parameters)
{
    return {};
}

ReturnCode_t DomainParticipant::delete_contentfilteredtopic(
    ContentFilteredTopic* content_filtered_topic)
{
    return ReturnCode_t::OK;
}

MultiTopic DomainParticipant::create_multitopic(
    const std::string& name,
    const std::string& type_name,
    const std::string& subscription_expression,
    const std::vector<std::string>& expression_parameters)
{
    return {};
}

ReturnCode_t DomainParticipant::delete_multitopic(
    MultiTopic* multi_topic)
{
    return ReturnCode_t::OK;
}

Topic *DomainParticipant::find_topic(
    const std::string& topic_name,
    Duration_t timeout)
{
    return nullptr;
}

TopicDescription* DomainParticipant::lookup_topicdescription(
    const std::string &name)
{
    return nullptr;
}

Subscriber *DomainParticipant::get_builtin_subscriber()
{
    return nullptr;
}

ReturnCode_t DomainParticipant::ignore_participant(
    InstanceHandle_t handle)
{

}

ReturnCode_t DomainParticipant::ignore_topic(
    InstanceHandle_t handle)
{

}

ReturnCode_t DomainParticipant::ignore_publication(
    InstanceHandle_t handle)
{

}

ReturnCode_t DomainParticipant::ignore_subscription(
    InstanceHandle_t handle)
{

}

DomainId_t DomainParticipant::get_domain_id()
{

}

ReturnCode_t DomainParticipant::delete_contained_entities()
{

}

ReturnCode_t DomainParticipant::assert_liveliness()
{

}

ReturnCode_t DomainParticipant::set_default_publisher_qos(
    const std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipant::get_default_publisher_qos(
    std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipant::set_default_subscriber_qos(
    const std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipant::get_default_subscriber_qos(
    std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipant::set_default_topic_qos(
    const std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipant::get_default_topic_qos(
    std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipant::get_discovered_participants(
    std::vector<InstanceHandle_t>& handles)
{

}

ReturnCode_t DomainParticipant::get_discovered_participant_data(
    ParticipantBuiltinTopicData& participant_data,
    InstanceHandle_t handle)
{

}

ReturnCode_t DomainParticipant::get_discovered_topics(
    std::vector<InstanceHandle_t>& handles)
{

}

ReturnCode_t DomainParticipant::get_discovered_topic_data(
    TopicBuiltinTopicData& topic_data,
    InstanceHandle_t handle)
{

}

bool DomainParticipant::contains_entity(InstanceHandle_t handle) const
{
    std::lock_guard<std::mutex> lock(impl_->entity_mutex_);
    auto iter = impl_->entities_.find(handle);
    return iter != impl_->entities_.end();
}

ReturnCode_t DomainParticipant::get_current_time(Time_t& current_time) const
{
    const static std::uint64_t ratio = 1000ll*1000*10000;
    auto now = std::chrono::system_clock::now();
    std::uint32_t nano = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
    current_time.sec = nano / ratio;
    current_time.nanosec = nano % ratio;
    return ReturnCode_t::OK;
}

}
}
