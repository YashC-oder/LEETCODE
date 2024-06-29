class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string currentWord = q.front().first;
            int level = q.front().second;
            q.pop();

            for (int i = 0; i < currentWord.size(); ++i) {
                string temp = currentWord;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    if (temp == endWord) {
                        return level + 1;
                    }
                    if (words.find(temp) != words.end()) {
                        q.push({temp, level + 1});
                        words.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};
