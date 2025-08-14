#pragma once
#include <vector>
#include <algorithm>

template <typename T>
class Heap {
    std::vector<T> data_;
public:
    void push(const T& value) {
        data_.push_back(value);
        std::push_heap(data_.begin(), data_.end());
    }
    void pop() {
        std::pop_heap(data_.begin(), data_.end());
        data_.pop_back();
    }
    const T& top() const { return data_.front(); }
    bool empty() const noexcept { return data_.empty(); }
    size_t size() const noexcept { return data_.size(); }
};
