class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indexes;
        
        if (words.empty() || s.empty()) {
            return indexes;
        }
        
        int wordLength = words[0].size();
        int numWords = words.size();
        int totalLength = wordLength * numWords;
        
        if (s.size() < totalLength) {
            return indexes;
        }
        
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        for (int i = 0; i <= s.size() - totalLength; ++i) {
            unordered_map<string, int> seen;
            int wordMatchCount = 0;
            
            for (int j = 0; j < totalLength; j += wordLength) {
                string currentWord = s.substr(i + j, wordLength);
                
                if (wordCount.find(currentWord) == wordCount.end()) {
                    break;
                }
                
                
                if (++seen[currentWord] > wordCount[currentWord]) {
                    break;
                }
                
                wordMatchCount++;
            }
            
            if (wordMatchCount == numWords) {
                indexes.push_back(i);
            }
        }
        
        return indexes;
    }
};
