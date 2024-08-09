#pragma once

#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/topic/Topic.h>
#include <simple_dds/dds/publisher/DataWriter.h>
#include <simple_dds/dds/subscriber/Subscriber.h>
#include <simple_dds/dds/subscriber/DataReader.h>

namespace simple_dds
{
namespace dds
{
/**
 * The purpose of the DomainParticipantListener is to be the listener of last resort that is notified of all status changes not
 * captured by more specific listeners attached to the DomainEntity objects. When a relevant status change occurs, the DCPS
 * Service will first attempt to notify the listener attached to the concerned DomainEntity if one is installed. Otherwise, the
 * DCPS Service will notify the Listener attached to the DomainParticipant.
 */
class DomainParticipantListener
{
public:
    virtual void on_inconsistent_topic(Topic *topic, const InconsistentTopicStatus &status) = 0;

    virtual void on_liveliness_lost(DataWriter *writer, const LivelinessLostStatus &status) = 0;

    virtual void on_offered_deadline_missed(DataWriter *writer, const OfferedDeadlineMissedStatus &status) = 0;

    virtual void on_data_on_readers(Subscriber *subscriber) = 0;

    virtual void on_sample_lost(DataReader *reader, const SampleLostStatus &status) = 0;

    virtual void on_data_available(DataReader *reader) = 0;

    virtual void on_sample_rejected(DataReader *reader, const SampleRejectedStatus &status) = 0;

    virtual void on_liveliness_changed(DataReader *reader, const LivelinessChangedStatus &status) = 0;

    virtual void on_requested_deadline_missed(DataReader *reader, const RequestedDeadlineMissedStatus &status) = 0;

    virtual void on_requested_incompatible_qos(DataReader *reader, const RequestedIncompatibleQosStatus &status) = 0;

    virtual void on_publication_matched(DataWriter *writer, const PublicationMatchedStatus &status) = 0;

    virtual void on_subscription_matched(DataReader *reader, const SubscriptionMatchedStatus &status) = 0;
};
}
}