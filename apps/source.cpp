#include <iostream>
#include "dsa/Stack.hpp"
#include "dsa/Queue.hpp"
#include "dsa/Heap.hpp"
#include "dsa/Graph.hpp"

// Forward declare BFS/DFS (from algorithms/)
std::vector<int> BFS(const Graph& g, int start);
std::vector<int> DFS(const Graph& g, int start);

int main() {
    Stack<int> s;
    s.push(1); s.push(2); s.push(3);
    std::cout << "Stack top: " << s.top() << "\n";
    s.pop();
    std::cout << "Stack top after pop: " << s.top() << "\n";

    Queue<int> q;
    q.enqueue(5); q.enqueue(6);
    std::cout << "Queue front: " << q.front() << "\n";
    q.dequeue();
    std::cout << "Queue front after dequeue: " << q.front() << "\n";

    Heap<int> h;
    h.push(10); h.push(4); h.push(15);
    std::cout << "Heap top: " << h.top() << "\n";

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    auto bfs_order = BFS(g, 0);
    auto dfs_order = DFS(g, 0);

    std::cout << "BFS: ";
    for (int v : bfs_order) std::cout << v << ' ';
    std::cout << "\nDFS: ";
    for (int v : dfs_order) std::cout << v << ' ';
    std::cout << "\n";

    return 0;
}
