#pragma once
#include <vector>

class Graph {
    std::vector<std::vector<int>> adj_;
public:
    Graph(int n) : adj_(n) {}
    void addEdge(int u, int v) {
        adj_[u].push_back(v);
        adj_[v].push_back(u);
    }
    const std::vector<int>& neighbors(int u) const { return adj_[u]; }
    int size() const noexcept { return adj_.size(); }
};
