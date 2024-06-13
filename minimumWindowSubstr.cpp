class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        // Frequency map for characters in t
        unordered_map<char, int> tFreq;
        for (char ch : t) {
            tFreq[ch]++;
        }
        
        int required = tFreq.size(); // Number of unique characters in t to be present in the window
        int formed = 0; // Number of unique characters in the current window that match the required frequency

        unordered_map<char, int> windowCounts;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minLeft = 0;

        while (right < s.size()) {
            char ch = s[right];
            windowCounts[ch]++;
            
            if (tFreq.find(ch) != tFreq.end() && windowCounts[ch] == tFreq[ch]) {
                formed++;
            }

            while (left <= right && formed == required) {
                ch = s[left];

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                windowCounts[ch]--;
                if (tFreq.find(ch) != tFreq.end() && windowCounts[ch] < tFreq[ch]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
