#pragma once

#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/publisher/DataWriter.h>

namespace simple_dds
{
namespace dds
{
class DataWriterListener
{
public:
    virtual ~DataWriterListener() = default;

    virtual void on_liveliness_lost(
        const DataWriter *writer,
        const LivelinessLostStatus& status) {};

    virtual void on_offered_deadline_missed(
        const DataWriter *writer,
        const OfferedDeadlineMissedStatus& status) {};

    virtual void on_offered_incompatible_qos(
        const DataWriter *writer,
        const OfferedIncompatibleQosStatus& status) {};

    virtual void on_publication_matched(
        const DataWriter *writer,
        const PublicationMatchedStatus& status) {};
};
}
}