#include <mutex>
#include <vector>
#include <unordered_map>
#include <simple_dds/dds/domain/DomainParticipant.h>
#include <simple_dds/dds/domain/DomainParticipantFactory.h>

namespace simple_dds
{
namespace dds
{
struct ParticipantInfo
{
    DomainId_t domain_id{0};
    DomainParticipantListener *listener{nullptr};
    StatusKinds status_kinds;
};

class DomainParticipantFactory::Impl
{
public:
    std::mutex participant_mutex_;
    std::unordered_map<DomainParticipant*, ParticipantInfo> participant_info_;
    std::vector<QosPolicy> default_qos_list_;
};

DomainParticipant *DomainParticipantFactory::create_participant(
    DomainId_t domain_id,
    const DomainParticipantQos &qos,
    DomainParticipantListener *listener,
    const StatusKinds &status_kinds)
{
    std::lock_guard<std::mutex> lock(impl_->participant_mutex_);
    auto participant = new DomainParticipant();
    ParticipantInfo info;
    info.domain_id = domain_id;
    info.listener = listener;
    info.status_kinds = status_kinds;
    impl_->participant_info_[participant] = info;
}

ReturnCode_t DomainParticipantFactory::delete_participant(
    DomainParticipant *participant)
{
    if (!participant)
    {
        return ReturnCode_t::BAD_PARAMETER;
    }

    std::lock_guard<std::mutex> lock(impl_->participant_mutex_);
    auto iter = impl_->participant_info_.find(participant);
    if (iter != impl_->participant_info_.cend())
    {
        //TODO: test all entity belong to participant is deleted
        delete participant;
        impl_->participant_info_.erase(iter);
        return ReturnCode_t::OK;
    }
    else
    {
        return ReturnCode_t::NO_DATA;
    }
}

DomainParticipant* DomainParticipantFactory::lookup_participant(
    DomainId_t domain_id)
{
    std::lock_guard<std::mutex> lock(impl_->participant_mutex_);
    for (const auto& item: impl_->participant_info_)
    {
        if (item.second.domain_id == domain_id)
        {
            return item.first;
        }
    }

    return nullptr;
}

ReturnCode_t DomainParticipantFactory::set_default_participant_qos(
    const std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipantFactory::get_default_participant_qos(
    std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipantFactory::get_qos(
    std::vector<QosPolicy>& qos_list)
{

}

ReturnCode_t DomainParticipantFactory::set_qos(
    const std::vector<QosPolicy>& qos_list)
{

}
}
}
