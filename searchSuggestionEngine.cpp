class Solution {
    private:
        struct Node{
            unordered_map<char,Node*> children;
            bool isEnd;
            Node():isEnd(false){}
        };
        Node* root;
        void insert(string word){
            Node* node = root;
            for(char ch : word){
                if(!node->children.count(ch)){
                    node->children[ch] = new Node();
                }
                node = node->children[ch];
            }
            node->isEnd = true;
        }
    
        void dfs(Node* node,string word,priority_queue<string>& pq){
            if(node->isEnd){
                pq.push(word);
                if(pq.size() > 3) pq.pop();
            }
    
            for(auto [key , value] : node->children){
                dfs(value,word+key,pq);
            }
    
        }
    
        vector<string> startWith(string word){
            Node* node = root;
            priority_queue<string> pq;
            for(char ch : word){
                if(!node->children.count(ch)) return {};
                node = node->children[ch];
            }
            dfs(node,word,pq);
    
            vector<string> generatedWords;
            
            while(!pq.empty()){
                generatedWords.insert(generatedWords.begin(),pq.top());
                pq.pop();
            }
    
            return generatedWords;
        }
    public:
        vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
            root = new Node();
            int length = searchWord.size();
            vector<vector<string>> words;
    
            for(string product : products){
                insert(product);
            }
    
            string word = "";
            for(int i = 0 ;i<length;i++){
                word += searchWord[i];
                words.push_back(startWith(word));
            }
    
            return words;
        }
    };