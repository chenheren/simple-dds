#pragma once

#include <string>

namespace simple_dds
{
enum class SampleRejectedStatusKind: std::uint8_t
{
    NOT_REJECTED,
    REJECTED_BY_INSTANCES_LIMIT,
    REJECTED_BY_SAMPLES_LIMIT,
    REJECTED_BY_SAMPLES_PER_INSTANCE_LIMIT
};

class SampleRejectedStatus
{
public:
    std::int16_t total_count;

    std::int16_t total_count_change;

    SampleRejectedStatusKind last_reason;


};
}