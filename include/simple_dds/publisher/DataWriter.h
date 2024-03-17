#pragma once

#include <vector>
#include <simple_dds/common/Type.h>
#include <simple_dds/common/Status.h>
#include <simple_dds/common/Listener.h>
#include <simple_dds/common/QosPolicy.h>

namespace simple_dds
{
class DataWriter
{
public:
    ReturnCode_t get_qos(std::vector<QosPolicy>& qos_list);

    ReturnCode_t set_qos(const std::vector<QosPolicy>& qos_list);

    Listener* get_listener();

    ReturnCode_t set_listener(Listener* listener, const std::vector<Status>& mask);

    ReturnCode_t register_instance(Data instance, InstanceHandle_t handle);

    ReturnCode_t unregister_instance_w_timestamp(Data instance, InstanceHandle_t handle, Time_t timestamp);

    ReturnCode_t unregister_instance(Data instance, InstanceHandle_t handle, Time_t timestamp);

    ReturnCode_t unregister_instance_w_timestamp(Data instance, InstanceHandle_t handle, Time_t timestamp);

    ReturnCode_t get_key(Data& instance, InstanceHandle_t handle);

    InstanceHandle_t lookup_instance(Data instance);

    ReturnCode_t write(Data data, InstanceHandle_t handle);

    ReturnCode_t dispose();
};
}