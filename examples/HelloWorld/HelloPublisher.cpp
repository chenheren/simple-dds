#include <atomic>
#include <thread>
#include <iostream>
#include <simple_dds/domain/DomainParticipantFactory.h>
#include <simple_dds/domain/DomainParticipant.h>
#include <simple_dds/publisher/Publisher.h>
#include <simple_dds/publisher/DataWriter.h>
#include <simple_dds/publisher/DataWriterListener.h>
#include <simple_dds/topic/Topic.h>

class HelloPublisher
{
public:
    HelloPublisher()
    {
        auto factory = simple_dds::DomainParticipantFactory::get_instance();
        participant_ = factory.create_participant(0, );
        publisher_ = participant_->create_publisher(qos, nullptr);
        topic_ = participant_->create_topic();
        writer_ = publisher_->create_writer();
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
            writer_->write();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    class DataWriterListener : public simple_dds::DataWriterListener
    {
    public:

        void on_publication_matched(simple_dds::DataWriter* writer,
                const simple_dds::PublicationMatchedStatus& info) override
        {

        }
    } listener_;


private:
    std::thread thread_;

    std::atomic<bool> running_{true};

    simple_dds::DomainParticipant* participant_;

    simple_dds::Publisher* publisher_;

    simple_dds::Topic* topic_;

    simple_dds::DataWriter* writer_;
};

int main()
{
    HelloPublisher publisher;
    publisher.Start();
    //! enter a key to exist.
    getchar();
    return 0;
}