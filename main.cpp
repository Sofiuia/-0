#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cassert>

class Graph
{
private:
    size_t _V;
    std::vector<std::set<int>> _adj;

    void DFS(int v, std::vector<bool>& visited) const
    {
        visited[v] = true;
        std::cout << "Visited (DFS): " << v << std::endl;

        for (auto neighbor : _adj[v])
        {
            if (!visited[neighbor])
            {
                DFS(neighbor, visited);
            }
        }
    }

public:
    Graph(size_t V) : _V(V)
    {
        _adj.resize(V);
    }

    void addEdge(size_t u, size_t v)
    {
        assert(u < _V && v < _V); // Виправлено <= на <
        _adj[u].insert(v);
        _adj[v].insert(u); // Для неорієнтованого графа
    }

    void print() const
    {
        for (size_t i = 0; i < _V; ++i)
        {
            std::cout << "Vertex " << i << " connected with: ";
            for (auto neighbor : _adj[i])
            {
                std::cout << neighbor << " ";
            }
            std::cout << '\n';
        }
    }

    void DFSFrom(size_t startVertex) const
    {
        assert(startVertex < _V);
        std::vector<bool> visited(_V, false);
        DFS(startVertex, visited);
    }

    void DFSAll() const
    {
        DFSFrom(0);
    }

    void BFSFrom(size_t startVertex) const
    {
        assert(startVertex < _V);
        std::vector<bool> visited(_V, false);
        std::queue<size_t> marked;

        visited[startVertex] = true;
        marked.push(startVertex);

        while (!marked.empty())
        {
            size_t u = marked.front();
            marked.pop();

            std::cout << "Visited (BFS): " << u << std::endl;

            for (auto neighbor : _adj[u])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    marked.push(neighbor);
                }
            }
        }
    }

    void BFSAll() const
    {
        BFSFrom(0);
    }
};

int main()
{
    Graph grh(6);

    grh.addEdge(0, 1);
    grh.addEdge(0, 2);
    grh.addEdge(1, 3);
    grh.addEdge(2, 4);
    grh.addEdge(3, 5);

    std::cout << "Graph connections:\n";
    grh.print();

    std::cout << "\nDepth-First Search from vertex 0:\n";
    grh.DFSFrom(0);

    std::cout << "\nBreadth-First Search from vertex 0:\n";
    grh.BFSFrom(0);

    return 0;
}
