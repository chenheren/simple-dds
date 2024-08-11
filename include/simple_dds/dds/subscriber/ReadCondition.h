#pragma once

#include <string>
#include <vector>
#include <simple_dds/dds/core/Type.h>

namespace simple_dds
{
namespace dds
{
class DataReader;

/**
 * ReadCondition objects are conditions specifically dedicated to read operations and attached to one DataReader.
 *
 * ReadCondition objects allow an application to specify the data samples it is interested in (by specifying the desired sample-
 * states, view-states, and instance-states). See the parameter definitions for DataReader's read/take operations.) This allows the
 * middleware to enable the condition only when suitable information is available24. They are to be used in conjunction with a
 * WaitSet as normal conditions. More than one ReadCondition may be attached to the same DataReader
 */
class ReadCondition
{
public:
    ReadCondition();

    /**
     * This operation returns the DataReader associated with the ReadCondition.
     * Note that there is exactly one DataReader associated with each ReadCondition.
     * @return
     */
    DataReader* get_datareader();

    std::vector<SampleStateKind> get_sample_state_mask();

    std::vector<ViewStateKind> get_view_state_mask();

    std::vector<InstanceStateKind> get_instance_state_mask();
};
}
}