#pragma once

#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Entity.h>

namespace simple_dds
{
namespace dds
{
class Subscriber;

class SubscriberListener: public Entity
{
public:
    virtual void on_data_on_readers(Subscriber* subscriber) {};
};
}
}