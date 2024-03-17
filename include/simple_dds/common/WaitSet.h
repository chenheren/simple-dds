#pragma once

#include <string>
#include <vector>

namespace simple_dds
{
class WaitSet
{
public:
    RetrunCode_t attach_condition(Condition a_condition);

    RetrunCode_t detach_condition(Condition a_condition);

    RetrunCode_t wait();


};

}