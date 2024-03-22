#pragma once

#include <string>
#include <vector>
#include <memory>
#include <simple_dds/common/Type.h>

namespace simple_dds
{
/**
 * A WaitSet object allows an application to wait until one or more of the attached Condition objects
 * has a trigger_value of TRUE or else until the timeout expires.
 */
class WaitSet
{
public:
    /**
     * Attaches a Condition to the WaitSet
     * It is possible to attach a Condition on a WaitSet that is currently being waited upon (via the wait operation).
     * In this case, if the Condition has a trigger_value of TRUE, then attaching the condition will unblock the WaitSet.
     * Adding a Condition that is already attached to the WaitSet has no effect.
     * Possible error codes returned in addition to the standard ones: OUT_OF_RESOURCES
     * @param condition
     * @return
     */
    RetrunCode_t attach_condition(Condition condition);

    /**
     * Detaches a Condition from the WaitSet.
     * If the Condition was not attached to the WaitSet, the operation will return PRECONDITION_NOT_MET.
     * Possible error codes returned in addition to the standard ones: PRECONDITION_NOT_MET.
     * @param condition
     * @return
     */
    RetrunCode_t detach_condition(Condition condition);

    /**
     * This operation allows an application thread to wait for the occurrence of certain conditions.
     * If none of the conditions attached to the WaitSet have a trigger_value of TRUE,
     * the wait operation will block suspending the calling thread.
     * The result of the wait operation is the list of all the attached conditions that have a trigger_value of TRUE
     * (i.e., the conditions that unblocked the wait).
     * The wait operation takes a timeout argument that specifies the maximum duration for the wait.
     * It this duration is exceeded and none of the attached Condition objects is true, wait will return with the return code TIMEOUT.
     * It is not allowed for more than one application thread to be waiting on the same WaitSet.
     * If the wait operation is invoked on a WaitSet that already has a thread blocking on it,
     * the operation will return immediately with the value PRECONDITION_NOT_MET.
     * @return
     */
    RetrunCode_t wait();

    /**
     * This operation retrieves the list of attached conditions
     * @param conditions
     * @return
     */
    ReturnCode_t get_conditions(std::vector<std::shared_ptr<Condition>>& conditions);
};

}