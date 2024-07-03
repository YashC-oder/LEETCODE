#include <unordered_map>
#include <string>
using namespace std;

class WordDictionary {
private:
    struct trieNode {
        unordered_map<char, trieNode*> children;
        bool isEnd;
        trieNode() : isEnd(false) {}
    };

    trieNode* root;

    bool search(string& word, int index, trieNode* node) {
        for (int i = index; i < word.size(); i++) {
            if (word[i] == '.') {
                for (auto& elem : node->children) {
                    if (search(word, i + 1, elem.second)) return true;
                }
                return false;
            }

            if (!node->children.count(word[i])) return false;
            node = node->children[word[i]];
        }
        return node->isEnd;
    }

public:
    WordDictionary() {
        root = new trieNode();
    }

    void addWord(string word) {
        trieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new trieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return search(word, 0, root);
    }
};
