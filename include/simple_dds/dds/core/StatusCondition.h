#pragma once

#include <string>
#include <vector>
#include <memory>
#include <simple_dds/dds/core/Type.h>
#include <simple_dds/dds/core/Status.h>
#include <simple_dds/dds/core/Condition.h>

namespace simple_dds
{
namespace dds
{
class Entity;

/**
 * A StatusCondition object is a specific Condition that is associated with each Entity.
 * The trigger_value of the StatusCondition depends on the communication status of that entity (
 * e.g., arrival of data, loss of information, etc.), ‘filtered’ by the set of enabled_statuses on the StatusCondition.
 */
class StatusCondition: public Condition
{
public:
    /**
     * Inherited from Condition
     * @return
     */
    bool get_trigger_value() override;

    /**
     * This operation defines the list of communication statuses that are taken into account to determine the
     * trigger_value of the StatusCondition. This operation may change the trigger_value of the StatusCondition.
     * WaitSet objects behavior depend on the changes of the trigger_value of their attached conditions.
     * Therefore, any WaitSet to which the StatusCondition is attached is potentially affected by this operation.
     * @param mask
     * @return
     */
    ReturnCode_t set_enabled_statuses(const std::vector<Status*>& mask);

    /**
     * This operation retrieves the list of communication statuses that are taken into account to determine the trigger_value of the StatusCondition.
     * This operation returns the statuses that were explicitly set on the last call to set_enabled_statuses or,
     * if set_enabled_statuses was never called, the default list (see 2.2.2.1.9.1)
     * @return
     */
    std::vector<Status*> get_enabled_statuses();

    /**
     * This operation returns the Entity associated with the StatusCondition.
     * Note that there is exactly one Entity associated with each StatusCondition.
     * @return
     */
    Entity* get_entity();
};

}
}