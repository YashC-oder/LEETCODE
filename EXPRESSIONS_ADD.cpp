class Solution {
public:
   
void helper(string num, vector<string>& expressions, string curr, long long prev, long long prev_last, int target) {
    if (num.empty()) {
        if (prev == target) {
            expressions.push_back(curr);
        }
        return;
    }
    
    for (int i = 1; i <= num.size(); ++i) {
        string left = num.substr(0, i);
        string right = num.substr(i);
        long long n = stoll(left);
        if (curr.empty()) {
            helper(right, expressions, left, n, n, target);
        } else {
            helper(right, expressions, curr + "+" + left, prev + n, n, target);
            helper(right, expressions, curr + "-" + left, prev - n, -n, target);
            helper(right, expressions, curr + "*" + left, prev - prev_last + prev_last * n, prev_last * n, target);
        }
        if (left[0] == '0') break;
    }
}


    vector<string> addOperators(string num, int target) {
        vector<string> expressions;
        helper(num, expressions, "", 0,0, target);
        return expressions;
    }
};

