#pragma once

#include <simple_dds/common/Type.h>
#include <simple_dds/subcriber/DataReader.h>

namespace simple_dds
{
class Subscriber: public Entity
{
public:
    void on_data_available(DataReader* reader);

    void on_sample_rejected(DataReader* reader, Sample);
};
}