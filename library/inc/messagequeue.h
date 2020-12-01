#include <condition_variable>
#include <list>
#include <mutex>
#include <optional>
#include <string>
#include <vector>

class MessageQueue
{
public:
    MessageQueue();
    ~MessageQueue();
    MessageQueue(const MessageQueue&);
    MessageQueue operator=(const MessageQueue&);

    std::optional<std::string> try_read();
    void write(std::string msg);
private:
    std::list<std::string> messages;
    std::mutex m;
};
