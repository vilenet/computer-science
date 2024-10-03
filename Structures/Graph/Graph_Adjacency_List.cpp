// A simple Graph example (using an adjacency list)
#include <unordered_map>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    std::unordered_map<int, std::list<int>> m_adjList;

private:
    void DFSUtil(int vertex, std::unordered_map<int, bool> &visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";
        for (int neighbor : m_adjList[vertex])
            if (!visited[neighbor]) { DFSUtil(neighbor, visited); }
    }

public:
    void addEdge(int vertex, int neighbor) { 
        m_adjList[vertex].push_back(neighbor);
    }

    void printGraph() {
        for (auto &vertex : m_adjList) {
            cout << "Vertex " << vertex.first << " is connected to: ";
            for (int neighbor : vertex.second) { cout << neighbor << " "; }
            cout << endl;
        }
    }

    void DFS(int startVertex) {
        unordered_map<int, bool> visited;    
        DFSUtil(startVertex, visited);
    }
};

int main() 
{
    Graph graph;

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    std::cout << "Graph representation:" << std::endl;
    graph.printGraph();

    std::cout << "\nDepth First Search starting from vertex 0:" << std::endl;
    graph.DFS(0);

    return 0;
}
