#include "dsa/Graph.hpp"
#include <vector>
#include <stack>

std::vector<int> DFS(const Graph& g, int start) {
    std::vector<int> visited;
    std::vector<bool> seen(g.size(), false);
    std::stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (seen[u]) continue;
        seen[u] = true;
        visited.push_back(u);
        for (int v : g.neighbors(u)) st.push(v);
    }
    return visited;
}
