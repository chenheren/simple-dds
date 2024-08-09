#pragma once

#include <simple_dds/dds/core/Type.h>

namespace simple_dds
{
namespace dds
{
/**
 * A DataSample represents an atom of data information (i.e., one value for one instance)
 * as returned by DataReader’s read/take operations.
 * It consists of two parts: A SampleInfo and the Data.
 */
class SampleInfo
{
public:
    SampleStateKind sample_state;
    ViewStateKind view_state;
    InstanceStateKind instance_state;
    std::uint32_t disposed_generation_count{0};
    std::uint32_t no_writers_generation_count{0};
    std::uint32_t sample_rank{0};
    std::uint32_t generation_rank{0};
    std::uint32_t absolute_generation_rank{0};
    Time_t source_timestamp{0, 0};
    InstanceHandle_t instance_handle{0};
    InstanceHandle_t publication_handle{0};
    bool valid_data;
};
}
}