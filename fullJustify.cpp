#include <vector>
#include <string>
#include <cmath>

class Solution {
private:
    string Space(int len) {
        return string(len, ' ');
    }

    string justify(vector<string> text, int length, int maxWidth) {
        int size = text.size();

        if (size == 1) {
            return text[0] + Space(maxWidth - length);
        }

        int totalSpaces = maxWidth - length + size -1;
        int spaceBetweenWords = totalSpaces / (size - 1);
        int extraSpaces = totalSpaces % (size - 1);

        string str = text[0];
        for (int i = 1; i < size; ++i) {
            int spacesToAdd = spaceBetweenWords + (i <= extraSpaces ? 1 : 0);
            str += Space(spacesToAdd) + text[i];
        }

        return str;
    }

    string leftJustify(vector<string> text, int maxWidth) {
        string str = text[0];

        for (int i = 1; i < text.size(); ++i) {
            str += " " + text[i];
        }

        return str + Space(maxWidth - str.length());
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justifiedText;
        int start = 0;
        int word_count = words.size();

        while (start < word_count) {
            vector<string> text;
            int length = words[start].length();
            text.push_back(words[start]);
            int next = start + 1;

            while (next < word_count && length + 1 + words[next].length() <= maxWidth) {
                length += 1 + words[next].length();
                text.push_back(words[next]);
                ++next;
            }

            if (next == word_count) {
                justifiedText.push_back(leftJustify(text, maxWidth));
            } else {
                justifiedText.push_back(justify(text, length, maxWidth));
            }

            start = next;
        }

        return justifiedText;
    }
};
