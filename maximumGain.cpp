class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Ensure we always handle the higher score pair first
        if (x < y) {
            swap(x, y);
            for (char& c : s) {
                if (c == 'a') c = 'b';
                else if (c == 'b') c = 'a';
            }
        }

        // Calculate score by removing "ab" pairs first
        int score = 0;
        string temp;
        for (char c : s) {
            if (!temp.empty() && temp.back() == 'a' && c == 'b') {
                temp.pop_back();
                score += x;
            } else {
                temp.push_back(c);
            }
        }

        // Calculate score by removing "ba" pairs from the remaining string
        s = temp;
        temp.clear();
        for (char c : s) {
            if (!temp.empty() && temp.back() == 'b' && c == 'a') {
                temp.pop_back();
                score += y;
            } else {
                temp.push_back(c);
            }
        }

        return score;
    }
};
