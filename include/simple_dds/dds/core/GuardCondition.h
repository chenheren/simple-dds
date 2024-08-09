#pragma once

#include <string>
#include <vector>
#include <memory>
#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Condition.h>

namespace simple_dds
{
namespace dds
{
/**
 * A GuardCondition object is a specific Condition whose trigger_value is completely under the control of the application.
 */
class GuardCondition: public Condition
{
public:
    /**
     * Inherited from Condition
     * @return
     */
    bool get_trigger_value() override;

    /**
     * This operation sets the trigger_value of the GuardCondition.
     * WaitSet objects behavior depends on the changes of the trigger_value of their attached conditions.
     * Therefore, any WaitSet to which is attached the GuardCondition is potentially affected by this operation.
     * @param value
     * @return
     */
    ReturnCode_t set_trigger_value(bool value);
};
}
}