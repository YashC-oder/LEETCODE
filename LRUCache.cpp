class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> map;

    void add(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        remove(node);
        add(node);
    }

    void popTail() {
        Node* node = tail->prev;
        remove(node);
        map.erase(node->key);
        delete node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            moveToHead(node);
        } else {
            if (map.size() >= capacity) {
                popTail();
            }
            Node* node = new Node(key, value);
            map[key] = node;
            add(node);
        }
    }
};
