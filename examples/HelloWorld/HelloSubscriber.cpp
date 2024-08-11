#include <atomic>
#include <thread>
#include <iostream>
#include <simple_dds/dds/topic/TypeSupport.h>
#include <simple_dds/dds/subscriber/Subscriber.h>
#include <simple_dds/dds/subscriber/DataReader.h>
#include <simple_dds/dds/subscriber/DataReaderListener.h>
#include <simple_dds/dds/domain/DomainParticipant.h>
#include <simple_dds/dds/domain/DomainParticipantFactory.h>

class HelloSubscriber
{
public:
    HelloSubscriber()
    {
        auto& factory = simple_dds::dds::DomainParticipantFactory::get_instance();
        simple_dds::dds::DomainParticipantQos participant_qos;
        participant_ = factory.create_participant(0, participant_qos);
        subscriber_ = participant_->create_subscriber({}, nullptr , {});
        topic_ = participant_->create_topic("HelloWorldTopic", "HelloWorld", {}, nullptr, {});
        reader_ = subscriber_->create_datareader(topic_, {}, &listener_);
    }

    ~HelloSubscriber()
    {
        running_ = false;
        if (thread_.joinable())
        {
            thread_.join();
        }
    }

private:
    class DataReaderListener : public simple_dds::dds::DataReaderListener
    {
    public:
        void on_data_available(
            simple_dds::dds::DataReader* reader) override
        {

        }

        void on_subscription_matched(
            simple_dds::dds::DataReader* reader,
            const simple_dds::dds::SubscriptionMatchedStatus& status) override
        {

        }
    } listener_;

private:
    std::thread thread_;
    std::atomic<bool> running_{true};

    simple_dds::dds::DomainParticipant* participant_;

    simple_dds::dds::Subscriber* subscriber_;

    simple_dds::dds::Topic* topic_;

    simple_dds::dds::DataReader* reader_;

    simple_dds::dds::TypeSupport type_;
};

int main()
{
    HelloSubscriber subscriber;
    //! enter a key to exist.
    getchar();
    return 0;
}