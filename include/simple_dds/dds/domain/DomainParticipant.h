#pragma once

#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Entity.h>
#include <simple_dds/dds/topic/Topic.h>
#include <simple_dds/dds/topic/TopicListener.h>
#include <simple_dds/dds/topic/MultiTopic.h>
#include <simple_dds/dds/topic/ContentFilteredTopic.h>
#include <simple_dds/dds/publisher/Publisher.h>
#include <simple_dds/dds/publisher/PublisherListener.h>
#include <simple_dds/dds/subscriber/Subscriber.h>
#include <simple_dds/dds/subscriber/SubscriberListener.h>
#include <simple_dds/dds/domain/DomainParticipantQos.h>

namespace simple_dds
{
namespace dds
{
class DomainParticipant: public Entity
{
public:

    /**
     * This operation creates a Publisher with the desired QoS policies and attaches to it the specified PublisherListener.
     * If the specified QoS policies are not consistent, the operation will fail and no Publisher will be created.
     * The special value PUBLISHER_QOS_DEFAULT can be used to indicate that the Publisher should be created with the
     * default Publisher QoS set in the factory.
     * The use of this value is equivalent to the application obtaining the default Publisher QoS by means of the
     * operation get_default_publisher_qos (2.2.2.2.1.21) and using the resulting QoS to create the Publisher.
     * The created Publisher belongs to the DomainParticipant that is its factory.
     * @param qos_list
     * @param listener
     * @param mask
     * @return publisher created, In case of failure, the operation will return nullptr
     */
    Publisher* create_publisher(
        const std::vector<QosPolicy>& qos_list,
        PublisherListener* listener,
        const std::vector<Status*>& mask);

    /**
     * This operation deletes an existing Publisher.
     * A Publisher cannot be deleted if it has any attached DataWriter objects.
     * If delete_publisher is called on a Publisher with existing DataWriter object, it will return PRECONDITION_NOT_MET.
     * The delete_publisher operation must be called on the same DomainParticipant object used to create the Publisher.
     * If delete_publisher is called on a different DomainParticipant, the operation will have no effect and it will return PRECONDITION_NOT_MET.
     * Possible error codes returned in addition to the standard ones: PRECONDITION_NOT_MET
     * @param publisher
     * @return
     */
    ReturnCode_t delete_publisher(
        const Publisher* publisher);

    /**
     * This operation creates a Subscriber with the desired QoS policies and attaches to it the specified SubscriberListener.
     * If the specified QoS policies are not consistent, the operation will fail and no Subscriber will be created.
     * The special value SUBSCRIBER_QOS_DEFAULT can be used to indicate that the Subscriber should be created with the
     * default Subscriber QoS set in the factory.
     * The use of this value is equivalent to the application obtaining the default Subscriber QoS by means of
     * the operation get_default_subscriber_qos (2.2.2.2.1.21) and using the resulting QoS to create the Subscriber.
     * The created Subscriber belongs to the DomainParticipant that is its factory.
     * @param qos_list
     * @param listener
     * @param mask
     * @return subscriber created,  In case of failure, the operation will return nullptr
     */
    Subscriber* create_subscriber(
        const std::vector<QosPolicy>& qos_list,
        SubscriberListener* listener,
        const std::vector<Status*>& mask);

    /**
     * This operation deletes an existing Subscriber.A Subscriber cannot be deleted if it has any attached DataReader objects.
     * If the delete_subscriber operation is called on a Subscriber with existing DataReader objects, it will return PRECONDITION_NOT_MET.
     * The delete_subscriber operation must be called on the same DomainParticipant object used to create the Subscriber.
     * If delete_subscriber is called on a different DomainParticipant, the operation will have no effect and it will return PRECONDITION_NOT_MET.
     * Possible error codes returned in addition to the standard ones: PRECONDITION_NOT_MET
     * @param subscriber
     * @return
     */
    ReturnCode_t delete_subscriber(
        Subscriber* subscriber);

    Topic *create_topic(
        const std::string& topic_name,
        const std::string& type_name,
        const std::vector<QosPolicy>& qos_list,
        TopicListener* listener,
        const std::vector<Status*>& mask);

    ReturnCode_t delete_topic(
        Topic* topic);

    ContentFilteredTopic create_contentfilteredtopic(
        const std::string& name,
        Topic* related_topic,
        const std::string& filter_expression,
        const std::vector<std::string>& expression_parameters);

    ReturnCode_t delete_contentfilteredtopic(
        ContentFilteredTopic* content_filtered_topic);

    MultiTopic create_multitopic(
        const std::string& name,
        const std::string& type_name,
        const std::string& subscription_expression,
        const std::vector<std::string>& expression_parameters);

    ReturnCode_t delete_multitopic(MultiTopic* multi_topic);

    Topic *find_topic(
        const std::string& topic_name,
        Duration_t timeout);

    TopicDescription* lookup_topicdescription(
        const std::string &name);

    Subscriber *get_builtin_subscriber();

    ReturnCode_t ignore_participant(
        InstanceHandle_t handle);

    ReturnCode_t ignore_topic(
        InstanceHandle_t handle);

    ReturnCode_t ignore_publication(
        InstanceHandle_t handle);

    ReturnCode_t ignore_subscription(
        InstanceHandle_t handle);

    DomainId_t get_domain_id();

    ReturnCode_t delete_contained_entities();

    ReturnCode_t assert_liveliness();

    ReturnCode_t set_default_publisher_qos(
        const std::vector<QosPolicy>& qos_list);

    ReturnCode_t get_default_publisher_qos(
        std::vector<QosPolicy>& qos_list);

    ReturnCode_t set_default_subscriber_qos(
        const std::vector<QosPolicy>& qos_list);

    ReturnCode_t get_default_subscriber_qos(
        std::vector<QosPolicy>& qos_list);

    ReturnCode_t set_default_topic_qos(
        const std::vector<QosPolicy>& qos_list);

    ReturnCode_t get_default_topic_qos(
        std::vector<QosPolicy>& qos_list);

    ReturnCode_t get_discovered_participants(
        std::vector<InstanceHandle_t>& handles);

    ReturnCode_t get_discovered_participant_data(
        ParticipantBuiltinTopicData& participant_data,
        InstanceHandle_t handle);

    ReturnCode_t get_discovered_topics(
        std::vector<InstanceHandle_t>& handles);

    ReturnCode_t get_discovered_topic_data(
        TopicBuiltinTopicData& topic_data,
        InstanceHandle_t handle);

    /**
     * This operation checks whether or not the given a_handle represents an Entity that was created from the DomainParticipant.
     * The containment applies recursively. That is, it applies both to entities (TopicDescription, Publisher, or Subscriber)
     * created directly using the DomainParticipant as well as entities created using a contained Publisher,
     * or Subscriber as the factory, and so forth
     * @param handle
     * @return
     */
    bool contains_entity(InstanceHandle_t handle) const;

    /**
     * This operation returns the current value of the time that the service uses to time-stamp data-writes and
     * to set the reception- timestamp for the data-updates it receives.
     * @param current_time
     * @return
     */
    ReturnCode_t get_current_time(Time_t &current_time) const ;

private:
    class Impl;
    Impl *impl_;
};
}
}