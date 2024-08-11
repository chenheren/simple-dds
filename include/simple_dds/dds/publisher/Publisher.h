#pragma once

#include <vector>
#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Status.h>
#include <simple_dds/dds/topic/Topic.h>

namespace simple_dds
{
namespace dds
{
class DataWriter;
class DataWriterListener;
class DomainParticipant;

/**
 * The Publisher acts on the behalf of one or several DataWriter objects that belong to it.
 * When it is informed of a change to the data associated with one of its DataWriter objects,
 * it decides when it is appropriate to actually send the data-update message.
 * In making this decision, it considers any extra information that goes with the data (timestamp, writer, etc.)
 * as well as the QoS of the Publisher and the DataWriter
 */
class Publisher
{
public:
    /**
     * This operation creates a DataWriter. The returned DataWriter will be attached and belongs to the Publisher.
     *
     * @param topic
     * @param qos
     * @param listener
     * @param mask
     * @return datawriter created, in case of failure, the operation will return nullptr
     */
    DataWriter* create_datawriter(
        Topic* topic,
        const std::vector<QosPolicy>& qos,
        DataWriterListener* listener,
        const std::vector<Status>& mask);

    ReturnCode_t delete_datawriter(
        DataWriter& writer);

    DataWriter* lookup_datawriter(
        const std::string& topic_name);

    ReturnCode_t suspend_publications();

    ReturnCode_t resume_publications();

    ReturnCode_t begin_coherent_changes();

    ReturnCode_t end_coherent_changes();

    ReturnCode_t wait_for_acknowledgments(
        const Duration_t& max_wait);

    DomainParticipant* get_participant();

    ReturnCode_t delete_contained_entities();

    ReturnCode_t set_default_datawriter_qos(
        const std::vector<QosPolicy>& qos_list);

    std::vector<QosPolicy> get_default_datawriter_qos();

    ReturnCode_t copy_from_topic_qos(
        std::vector<QosPolicy>& datawriter_qos,
        const std::vector<QosPolicy>& topic_qos);

private:
    class Impl;
    Impl* impl_;
};
}
}