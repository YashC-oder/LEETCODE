// RECURSIVE : 3ms
class Solution {
private:
    unordered_map<Node*, Node*> Nodes;
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (Nodes.find(head) != Nodes.end()) {
            return Nodes[head];
        }
        Node* node = new Node(head->val);
        Nodes[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};

/*----------------------------------------------------------------------------------------*/
// ITERATIVE : 3ms
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> nodeMap;
        
        Node* current = head;
        while (current) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }
        
        current = head;
        while (current) {
            nodeMap[current]->next = nodeMap[current->next];
            nodeMap[current]->random = nodeMap[current->random];
            current = current->next;
        }
        
        return nodeMap[head];
    }
};
