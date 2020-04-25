#ifndef LOGGER_H
#define LOGGER_H

#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>
#include <string_view>
#include <thread>

namespace parsella {
namespace utils {
class Logger {
public:
    // Starts a background thread writing log entries to a file.
    Logger();
    // Gracefully shut down background thread.
    virtual ~Logger();
    // Prevent copy construction and assignment.
    Logger(const Logger& src) = delete;
    Logger& operator=(const Logger& rhs) = delete;
    // Add log entry to the queue.
    void log(std::string_view entry);

private:
    // The function running in the background thread.
    void processEntries();
    // Boolean telling the background thread to terminate.
    bool mExit = false;
    // Mutex and condition variable to protect access to the queue.
    std::mutex mMutex;
    std::condition_variable mCondVar;
    std::queue<std::string> mQueue;
    // The background thread.
    std::thread mThread;
};
}  // namespace utils
}  // namespace parsella
#endif
