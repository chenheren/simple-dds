#pragma once

#include <simple_dds/common/Type.h>
#include <simple_dds/publisher/Publisher.h>

namespace simple_dds
{
class DomainParticipant: public Entity
{
public:
    Publisher* create_publisher();

    ReturnCode_t delete_publisher();

    
}
}