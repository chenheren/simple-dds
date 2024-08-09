#pragma once

#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/subscriber/SampleInfo.h>

namespace simple_dds
{
namespace dds
{
class DataReader;

class DataReaderListener
{
public:
    virtual void on_data_available(
        DataReader *reader) {};

    virtual void on_sample_rejected(
        DataReader *reader,
        const SampleRejectedStatus& status) {};

    virtual void on_liveliness_changed(
        DataReader* reader,
        const LivelinessChangedStatus& status) {};

    virtual void on_requested_deadline_missed(
        DataReader* reader,
        const RequestedDeadlineMissedStatus& status) {};

    virtual void on_requested_incompatible_qos(
        DataReader* reader,
        const RequestedIncompatibleQosStatus& status) {};

    virtual void on_subscription_matched(
        DataReader* reader,
        const SubscriptionMatchedStatus& status) {};

    virtual void on_sample_lost(
        DataReader* reader,
        const SampleLostStatus& status) {};
};
}
}