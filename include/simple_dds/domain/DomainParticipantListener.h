#pragma once

#include <simple_dds/common/Type.h>

namespace simple_dds
{
class DomainParticipantListener
{
public:
    void on_inconsistent_topic();
};
}