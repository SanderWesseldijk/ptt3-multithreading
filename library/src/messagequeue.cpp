#include "messagequeue.h"

#include <cassert>
#include <thread>

using namespace std::literals::chrono_literals;

MessageQueue::MessageQueue()
{
    
}

MessageQueue::~MessageQueue()
{

}

std::optional<std::string> MessageQueue::try_read()
{
    std::lock_guard<std::mutex>(*m);
    if (messages.empty())
    {
        return std::nullopt;
    }
    else
    {
        auto result = std::move(messages.front());
        messages.pop_front();
        return result;
    }
}

void MessageQueue::write(const std::string msg)
{
    std::lock_guard<std::mutex>(*m);
    messages.push_back(std::move(msg));
}