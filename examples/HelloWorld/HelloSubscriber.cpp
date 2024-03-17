#include <atomic>
#include <thread>
#include <iostream>

class HelloSubscriber
{
public:
    HelloSubscriber()
    {

    }

    ~HelloSubscriber()
    {
        running_ = false;
        if (thread_.joinable())
        {
            thread_.join();
        }
    }

    void Start()
    {
        thread_ = std::thread(&HelloSubscriber::Run, this);
    }


private:
    void Run()
    {
        while (running_)
        {

        }
    }

private:
    std::thread thread_;
    std::atomic<bool> running_{true};
};

int main()
{
    HelloSubscriber subscriber;
    subscriber.Start();

    char ch;
    while ((ch = getchar()))
    {

    }

    return 0;
}