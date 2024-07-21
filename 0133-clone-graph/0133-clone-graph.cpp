/*
// Definition for a Node.
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
*/

class Solution {
private:
    unordered_map<Node*, Node*> visited;

    Node* clone(Node* node) {
        if (!node) return nullptr;

        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a new node with the value of the old node.
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        // Iterate through the neighbors to generate their clones.
        for (auto neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(clone(neighbor));
        }

        return cloneNode;
    }

public:
    Node* cloneGraph(Node* node) {
        return clone(node);
    }
};