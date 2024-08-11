#include <mutex>
#include <memory>
#include <unordered_map>
#include <simple_dds/dds/subscriber/DataReader.h>
#include <simple_dds/dds/subscriber/DataReaderListener.h>
#include <simple_dds/dds/subscriber/Subscriber.h>

namespace simple_dds
{
namespace dds
{
struct DataReaderInfo
{
    TopicDescription topic_description;
    std::vector<QosPolicy> qos_list;
    DataReaderListener* listener;
    StatusKinds status;
};

class Subscriber::Impl
{
public:
    DomainParticipant* participant_;

    std::mutex reader_mutex_;
    std::unordered_map<DataReader*, std::shared_ptr<DataReaderInfo>> datareader_infos_;
};

Subscriber::Subscriber(
    DomainParticipant* participant)
{
    impl_->participant_ = participant;
}

DataReader* Subscriber::create_datareader(
    const TopicDescription* topic_description,
    const std::vector<QosPolicy>& qos_list,
    DataReaderListener* listener,
    const StatusKinds& status)
{
    std::lock_guard<std::mutex> lock(impl_->reader_mutex_);
    auto reader = new DataReader();
    auto info = std::make_shared<DataReaderInfo>();
    info->topic_description = *topic_description;
    info->listener = listener;
    info->status = status;
    impl_->datareader_infos_[reader] = info;
}

ReturnCode_t Subscriber::delete_datareader(
    DataReader* data_reader)
{
    std::lock_guard<std::mutex> lock(impl_->reader_mutex_);
    auto iter = impl_->datareader_infos_.find(data_reader);
    if (iter != impl_->datareader_infos_.cend())
    {
        impl_->datareader_infos_.erase(iter);
    }
}

DataReader* Subscriber::lookup_datareader(
    const std::string& topic_name)
{
    std::lock_guard<std::mutex> lock(impl_->reader_mutex_);
    for (const auto& item: impl_->datareader_infos_)
    {
        if (item.second->topic_description.get_name() == topic_name)
        {
            return item.first;
        }
    }

    return nullptr;
}

ReturnCode_t Subscriber::begin_access()
{

}

ReturnCode_t Subscriber::end_access()
{

}

ReturnCode_t Subscriber::get_datareader(
    std::vector<DataReader*>& readers,
    const std::vector<SampleStateKind>& sample_states,
    const std::vector<ViewStateKind>& view_states,
    const std::vector<InstanceStateKind>& instance_states)
{

}

ReturnCode_t Subscriber::notify_datareader()
{

}

DomainParticipant* Subscriber::get_participant()
{
    return impl_->participant_;
}

ReturnCode_t Subscriber::delete_contained_entities()
{

}

ReturnCode_t Subscriber::set_default_datareader_qos(
    const std::vector<QosPolicy> &qos)
{

}

ReturnCode_t Subscriber::get_default_datareader_qos(
    std::vector<QosPolicy> &qos)
{

}

ReturnCode_t Subscriber::copy_from_topic_qos(
    std::vector<QosPolicy>& datareader_qos,
    const std::vector<QosPolicy>& topic_qos)
{

}
}
}
