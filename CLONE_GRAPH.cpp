#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> nodes;

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        if (nodes.find(node) != nodes.end()) {
            return nodes[node];
        }

        Node* clonedNode = new Node(node->val);
        nodes[node] = clonedNode;

        for (Node* neighbor : node->neighbors) {
            clonedNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return clonedNode;
    }
};
