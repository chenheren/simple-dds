#pragma once

#include <memory>
#include <vector>
#include <simple_dds/core/base/Type.h>

namespace simple_dds
{
class StatusMask
{
public:
    inline static StatusMask all();
};
}