#pragma once
#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
    std::vector<T> data_;
public:
    void push(const T& value) { data_.push_back(value); }
    void push(T&& value) { data_.push_back(std::move(value)); }
    void pop() {
        if (empty()) throw std::underflow_error("Stack empty");
        data_.pop_back();
    }
    T& top() {
        if (empty()) throw std::underflow_error("Stack empty");
        return data_.back();
    }
    const T& top() const {
        if (empty()) throw std::underflow_error("Stack empty");
        return data_.back();
    }
    bool empty() const noexcept { return data_.empty(); }
    size_t size() const noexcept { return data_.size(); }
};
