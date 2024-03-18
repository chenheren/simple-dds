#pragma once

#include <simple_dds/common/Type.h>
#include <simple_dds/publisher/DataWriter.h>

namespace simple_dds
{
class DataWriterListener
{
public:
    virtual void on_liveliness_lost(DataWriter* writer, LivelinessLostStatus status) = 0;

    virtual void on_offered_deadline_missed(DataWriter* writer, OfferedDeadlineMissedStatus status) = 0;

    virtual void on_offered_incompatible_qos(DataWriter* writer, OfferedIncompatibleQosStatus status) = 0;

    virtual void on_publication_matched(DataWriter* writer, PublicationMatchedStatus status) = 0;
};
}