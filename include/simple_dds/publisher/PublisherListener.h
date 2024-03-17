#pragma once

#include <simple_dds/common/Type.h>

namespace simple_dds
{
class PublisherListener
{
public:
    void on_liveliness_lost(DataWriter writer, OfferedDeadlineMissedStatus status);


};
}