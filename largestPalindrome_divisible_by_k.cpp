// tle
class Solution {
private:
    string maxPalindromicNum(string num, int k, int index) {
        int size = num.size();
        if (index > size / 2) {
            return num;
        }

        string largest = "-1";
        for (int i = 9; i >= 0; i--) { 
            num[index] = i + '0';
            if (size - index - 1 >= 0) num[size - index - 1] = i + '0';

            string candidate = maxPalindromicNum(num, k, index + 1);

            if (candidate > largest && stoll(candidate) % k == 0) {
                largest = candidate;
            }
        }

        return largest;
    }

public:
    string largestPalindrome(int n, int k) {
        string num = "";
        for (int i = 0; i < n; i++) {
            num.push_back('9'); 
        }

        return maxPalindromicNum(num, k, 0);
    }
};
