#include <atomic>
#include <thread>
#include <iostream>
#include <simple_dds/dds/domain/DomainParticipantFactory.h>
#include <simple_dds/dds/domain/DomainParticipant.h>
#include <simple_dds/dds/publisher/Publisher.h>
#include <simple_dds/dds/publisher/DataWriter.h>
#include <simple_dds/dds/publisher/DataWriterListener.h>
#include <simple_dds/dds/topic/Topic.h>

class HelloPublisher
{
public:
    HelloPublisher()
    {
        auto factory = simple_dds::dds::DomainParticipantFactory::get_instance();
        simple_dds::dds::DomainParticipantQos participant_qos;
        participant_ = factory.create_participant(1, participant_qos);
        publisher_ = participant_->create_publisher({}, nullptr, {});
        topic_ = participant_->create_topic("HelloWorldTopic", "HelloWorld", {}, nullptr, {});
        writer_ = publisher_->create_datawriter(topic_, {}, nullptr, {});
    }

    ~HelloPublisher()
    {
        running_ = false;
        if (thread_.joinable())
        {
            thread_.join();
        }
    }

    void Start()
    {
        thread_ = std::thread(&HelloPublisher::Run, this);
    }


private:
    void Run()
    {
        while (running_)
        {
            writer_->write(nullptr, 0);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    class DataWriterListener : public simple_dds::dds::DataWriterListener
    {
    public:
        void on_publication_matched(
            const simple_dds::dds::DataWriter* writer,
            const simple_dds::dds::PublicationMatchedStatus& info) override
        {

        }
    } listener_;


private:
    std::thread thread_;

    std::atomic<bool> running_{true};

    simple_dds::dds::DomainParticipant* participant_;

    simple_dds::dds::Publisher* publisher_;

    simple_dds::dds::Topic* topic_;

    simple_dds::dds::DataWriter* writer_;
};

int main()
{
    HelloPublisher publisher;
    publisher.Start();
    //! enter a key to exist.
    getchar();
    return 0;
}