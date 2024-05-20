/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    Node* ParentNode(Node* root, int target, unordered_map<Node*, Node*>& Parent) {
        Node* targetNode = nullptr;
        queue<Node*> q;
        q.push(root);

        Parent[root] = nullptr;

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (front->data == target) {
                targetNode = front;
            }

            if (front->left) {
                Parent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                Parent[front->right] = front;
                q.push(front->right);
            }
        }

        return targetNode;
    }

    int burnTree(Node* targetNode, unordered_map<Node*, Node*>& Parent) {
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }

                if (front->right && !visited[front->right]) {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }

                if (Parent[front] && !visited[Parent[front]]) {
                    flag = true;
                    q.push(Parent[front]);
                    visited[Parent[front]] = true;
                }
            }

            if (flag) {
                time++;
            }
        }

        return time;
    }

  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> Parent;
        Node* targetNode = ParentNode(root, target, Parent);
        return burnTree(targetNode, Parent);
    }
};