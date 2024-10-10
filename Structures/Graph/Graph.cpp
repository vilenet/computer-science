#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <memory>

class Edge {
public:
    int weight;           
    struct Node* adjNode;

    Edge(Node* adjNode, int weight) : adjNode(adjNode), weight(weight) {}
};

class Node {
public:
    int value;                                     
    std::unordered_set<std::shared_ptr<Edge>> edges;
    std::unordered_map<Node*, std::shared_ptr<Edge>> parents;

    Node(int value) : value(value) {}
};

//
// Graph
//
class Graph {
private:
    std::unordered_map<int, std::unique_ptr<Node>> graph;

public:
    Graph(const std::vector<std::vector<int>>& graphData);
    void addNode(int value);
    Node* getNode(int value) const;
    void createGraph(const std::vector<std::vector<int>>& graphData);
    void printGraph() const;
};

//
// Graph Implementation
//
Graph::Graph(const std::vector<std::vector<int>>& graphData) {
    createGraph(graphData);
}

void Graph::addNode(int value) {
    if (graph.find(value) == graph.end()) {
        graph[value] = std::make_unique<Node>(value);
    }
}

Node* Graph::getNode(int value) const {
    auto it = graph.find(value);
    return (it != graph.end()) ? it->second.get() : nullptr;
}

void Graph::createGraph(const std::vector<std::vector<int>>& graphData) {
    for (const auto& row : graphData) {
        // Получаем или добавляем первый узел
        Node* node = getNode(row[0]);
        if (!node) {
            addNode(row[0]);
            node = getNode(row[0]);
        }

        // Получаем или добавляем смежный узел
        Node* adjNode = getNode(row[1]);
        if (!adjNode) {
            addNode(row[1]);
            adjNode = getNode(row[1]);
        }

        // Создаем ребро и добавляем его в узел
        if (adjNode != nullptr) {
            auto edge = std::make_shared<Edge>(adjNode, row[2]);
            node->edges.insert(edge);
            adjNode->parents[node] = edge;
        }
    }
}

void Graph::printGraph() const {
    for (const auto& pair : graph) {
        std::cout << "Node " << pair.first << " has edges to: ";
        for (const auto& edge : pair.second->edges) {
            std::cout << edge->adjNode->value << " (weight: " << edge->weight << ") ";
        }
        std::cout << std::endl;
    }
}

int main() 
{
    // Входные данные для создания графа
    std::vector<std::vector<int>> graphData = {
        {1, 2, 10}, {1, 3, 5}, {2, 4, 3}, {3, 4, 2}, {4, 5, 7}
    };

    Graph graph(graphData);

    // Печать графа
    graph.printGraph();

    return 0;
}
