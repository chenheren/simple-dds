#pragma once

#include <memory>
#include <vector>
#include <bitset>
#include <simple_dds/dds/core/Type.h>

namespace simple_dds
{
namespace dds
{
/**
 * StatusKins is a collection of status, every bit indicate a concrete status
 */
class StatusKinds
{
public:
    const static std::uint8_t KindSize = 16;

    StatusKinds(
        std::uint32_t mask)
    : value_(mask)
    {

    }

    inline static StatusKinds all()
    {
        return {0xFFFF};
    }

private:
    std::bitset<KindSize> value_;
};
}
}