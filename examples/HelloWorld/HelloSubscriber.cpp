#include <atomic>
#include <thread>
#include <iostream>
#include <simple_dds/common/Type.h>
#include <simple_dds/domain/DomainParticipantFactory.h>
#include <simple_dds/subcriber/Subscriber.h>
#include <simple_dds/subcriber/DataReader.h>
#include <simple_dds/subcriber/DataReaderListener.h>

class HelloSubscriber
{
public:
    HelloSubscriber()
    {
        auto& factory = simple_dds::DomainParticipantFactory::GetInstance();
        participant_ = factory.create_participant(0, );
        subscriber_ = participant_->create_subscriber(qos, nullptr);
        topic_ = participant_->create_topic("HelloWorldTopic", "HelloWorld", tqos);
        reader_ = subscriber_->create_datareader(topic_, rqos, &listener_);
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
    class DataReaderListener : public simple_dds::DataReaderListener
    {
    public:
        void on_data_available(
                simple_dds::DataReader* reader) override
        {

        }

        void on_subscription_matched(
                simple_dds::DataReader* reader,
                const simple_dds::SubscriptionMatchedStatus& info) override
        {

        }
    } listener_;

private:
    std::thread thread_;
    std::atomic<bool> running_{true};

    simple_dds::DomainParticipant* participant_;

    simple_dds::Subscriber* subscriber_;

    simple_dds::Topic* topic_;

    simple_dds::DataReader* reader_;

    simple_dds::TypeSupport type_;
};

int main()
{
    HelloSubscriber subscriber;
    //! enter a key to exist.
    getchar();
    return 0;
}