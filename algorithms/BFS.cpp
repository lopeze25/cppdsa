#include "dsa/Graph.hpp"
#include <vector>
#include <queue>

std::vector<int> BFS(const Graph& g, int start) {
    std::vector<int> visited;
    std::vector<bool> seen(g.size(), false);
    std::queue<int> q;
    q.push(start);
    seen[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited.push_back(u);
        for (int v : g.neighbors(u)) {
            if (!seen[v]) {
                seen[v] = true;
                q.push(v);
            }
        }
    }
    return visited;
}
