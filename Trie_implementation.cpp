class Trie {
struct Node{
    unordered_map<char,Node*> children;
    bool isEnd;
    Node():isEnd(false){}
};
Node* root;
public:
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->children.count(ch)){
                node->children[ch] = new Node();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->children.count(ch)){
                return false;
            }
            node = node->children[ch];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix){
            if(!node->children.count(ch)){
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};
