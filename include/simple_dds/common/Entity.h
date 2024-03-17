#pragma once

#include <memory>
#include <vector>
#include <simple_dds/common/Type.h>
#include <simple_dds/common/Status.h>
#include <simple_dds/common/Listener.h>
#include <simple_dds/common/QosPolicy.h>
#include <simple_dds/common/StatusCondition.h>

namespace simple_dds
{
 class Entity
 {
 public:
     virtual ReturnCode_t set_qos(const std::vector<QosPolicy>& qos_list) = 0;

     virtual ReturnCode_t get_qos(std::vector<QosPolicy>& qos_list) = 0;

     virtual ReturnCode_t set_listener(Listener* listener, const std::vector<Status>& mask) = 0;

     virtual Listener* get_listener() = 0;

     virtual StatusCondition get_statuscondition() = 0;

     virtual std::vector<Status> get_status_changes() = 0;

     virtual ReturnCode_t enable() = 0;

     virtual std::shared_ptr<Entity> get_instance_handle() = 0;
 };
}