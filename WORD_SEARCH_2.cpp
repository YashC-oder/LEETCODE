class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() {
        isEnd = false;
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    // Check if a word exists in the Trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEnd;
    }

    // Get the root of the Trie
    TrieNode* getRoot() {
        return root;
    }
};

class Solution {
private:
    void backtrack(vector<vector<char>>& board, int row, int col, TrieNode* node, string& path, vector<string>& result) {
        char original = board[row][col];
        if (!node->children.count(original)) {
            return; // No valid path in Trie for current character
        }

        // Update current path
        path.push_back(original);
        board[row][col] = '#'; // Mark as visited

        TrieNode* nextNode = node->children[original];

        // Check if we reached a valid word
        if (nextNode->isEnd) {
            result.push_back(path);
            nextNode->isEnd = false; // Mark as visited in Trie
        }

        // Directions for neighbors (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Explore neighbors
        for (auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() && board[newRow][newCol] != '#') {
                backtrack(board, newRow, newCol, nextNode, path, result);
            }
        }

        // Restore the board and path
        board[row][col] = original;
        path.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }

        vector<string> result;
        string path;

        int m = board.size();
        int n = board[0].size();

        // Start DFS from each cell on the board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtrack(board, i, j, trie.getRoot(), path, result);
            }
        }

        return result;
    }
};
