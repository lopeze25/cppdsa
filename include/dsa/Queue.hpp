#pragma once
#include <queue>

template <typename T>
class Queue {
    std::queue<T> data_;
public:
    void enqueue(const T& value) { data_.push(value); }
    void dequeue() { data_.pop(); }
    T& front() { return data_.front(); }
    bool empty() const noexcept { return data_.empty(); }
    size_t size() const noexcept { return data_.size(); }
};
