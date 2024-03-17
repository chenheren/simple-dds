#pragma once

#include <string>

namespace simple_dds
{
class Status
{
public:

};

class InconsistentTopicStatus
{
public:
    std::int16_t total_count;
    std::int16_t total_count_change;
};
}