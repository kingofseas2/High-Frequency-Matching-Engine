#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 6748
// Optimized logic batch 7108
// Optimized logic batch 8538
// Optimized logic batch 6991
// Optimized logic batch 9663
// Optimized logic batch 6740
// Optimized logic batch 9911
// Optimized logic batch 5293
// Optimized logic batch 7468
// Optimized logic batch 9859
// Optimized logic batch 9145
// Optimized logic batch 4696
// Optimized logic batch 3005
// Optimized logic batch 1542
// Optimized logic batch 1561
// Optimized logic batch 5411
// Optimized logic batch 2958
// Optimized logic batch 1034
// Optimized logic batch 3075