#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>

class BTreePrinter {
public:
    template<typename T>
    static void printNode(std::shared_ptr<Node<T>> root) {
        int maxLevel = maxLevelHelper(root);
        std::vector<std::shared_ptr<Node<T>>> nodes = { root };
        printNodeInternal(nodes, 1, maxLevel);
    }

private:
    template<typename T>
    static void printNodeInternal(std::vector<std::shared_ptr<Node<T>>> nodes, int level, int maxLevel) {
        if (nodes.empty() || isAllElementsNull(nodes)) return;

        int floor = maxLevel - level;
        int edgeLines = std::pow(2, std::max(floor - 1, 0));
        int firstSpaces = std::pow(2, floor) - 1;
        int betweenSpaces = std::pow(2, floor + 1) - 1;

        printWhitespaces(firstSpaces);

        std::vector<std::shared_ptr<Node<T>>> newNodes;
        for (auto& node : nodes) {
            if (node != nullptr) {
                std::cout << node->data;
                newNodes.push_back(node->left);
                newNodes.push_back(node->right);
            } else {
                newNodes.push_back(nullptr);
                newNodes.push_back(nullptr);
                std::cout << " ";
            }

            printWhitespaces(betweenSpaces);
        }
        std::cout << std::endl;

        for (int i = 1; i <= edgeLines; ++i) {
            for (size_t j = 0; j < nodes.size(); ++j) {
                printWhitespaces(firstSpaces - i);
                if (nodes[j] == nullptr) {
                    printWhitespaces(edgeLines + edgeLines + i + 1);
                    continue;
                }

                if (nodes[j]->left != nullptr) {
                    std::cout << "/";
                } else {
                    printWhitespaces(1);
                }

                printWhitespaces(i + i - 1);

                if (nodes[j]->right != nullptr) {
                    std::cout << "\\";
                } else {
                    printWhitespaces(1);
                }

                printWhitespaces(edgeLines + edgeLines - i);
            }
            std::cout << std::endl;
        }

        printNodeInternal(newNodes, level + 1, maxLevel);
    }

    static void printWhitespaces(int count) {
        for (int i = 0; i < count; ++i) {
            std::cout << " ";
        }
    }

    template<typename T>
    static int maxLevelHelper(std::shared_ptr<Node<T>> node) {
        if (node == nullptr) return 0;
        return std::max(maxLevelHelper(node->left), maxLevelHelper(node->right)) + 1;
    }

    template<typename T>
    static bool isAllElementsNull(const std::vector<std::shared_ptr<Node<T>>>& list) {
        for (auto& node : list) {
            if (node != nullptr) return false;
        }
        return true;
    }
};