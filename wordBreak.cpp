class Solution {
private:
    class Trie {
        struct Node{
            unordered_map<char,Node*> children;
            bool isEnd;
            Node():isEnd(false){}
        };
        Node* root;
    public:
        Trie() {
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
    };

    bool wordBreakHelper(string word, Trie* root, unordered_map<string, bool>& memo){
        if(word == "") return true;
        if(memo.find(word) != memo.end()) return memo[word];
        
        int size = word.size();
        string str = "";

        for(int i = 0; i < size; i++){
            str += word[i];
            if(root->search(str) && wordBreakHelper(word.substr(i+1, size-i-1), root, memo)){
                memo[word] = true;
                return true;
            }
        }
        memo[word] = false;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* root = new Trie();
        for(string word : wordDict){
            root->insert(word);
        }
        unordered_map<string, bool> memo;
        return wordBreakHelper(s, root, memo);
    }
};


/*----------------------------------------------------------------------------------------------------------- */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        
        dp[0] = true;
        int max_len = 0;
        for(auto i: wordDict) if(i.length() > max_len) max_len = i.length();

        for(int i=1; i<=n; i++) {
            for(int j=i-1; j>=max(i-max_len-1, 0); j--){
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};