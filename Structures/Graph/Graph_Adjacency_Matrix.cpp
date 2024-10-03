// A simple Graph example (using an adjacency matrix)
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int m_vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) : m_vertices(vertices) {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printGraph() {
        for (int i = 0; i < m_vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < m_vertices; j++) { cout << adjMatrix[i][j] << " "; }
            cout << endl;
        }
    }
};

int main() 
{
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Graph adjacency matrix:" << endl;
    graph.printGraph();

    return 0;
}
