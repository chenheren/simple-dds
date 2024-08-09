#pragma once

#include <string>
#include <vector>
#include <memory>
#include <simple_dds/dds/core/Type.h>

namespace simple_dds
{
namespace dds
{
/**
 * A Condition is a root class for all the conditions that may be attached to a WaitSet.
 * This basic class is specialized in three classes that are known by the middleware:
 * GuardCondition (2.2.2.1.8), StatusCondition (2.2.2.1.9), and ReadCondition (2.2.2.5.8).
 */
class Condition
{
public:
    /**
     * This operation retrieves the trigger_value of the Condition.
     * @return
     */
    virtual bool get_trigger_value()
    {
        return false;
    };
};

}
}