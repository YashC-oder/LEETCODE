class Solution {
public:
    vector<int> multiply(int num, const vector<int>& vec) {
        int num_size = floor(log10(num)) + 1;
        int size = vec.size();
        vector<int> ans(size + num_size, 0);
        long long carry = 0;

        for (int i = size - 1; i >= 0; --i) {
            long long product = vec[i] * num + carry;
            ans[i + num_size] = product % 10;
            carry = product / 10;
        }
        while (carry > 0) {
            ans[--num_size] = carry % 10;
            carry /= 10;
        }
        while (ans.size() > 1 && ans.front() == 0) {
            ans.erase(ans.begin());
        }

        return ans;
    }

    vector<int> factorial(int n) {
        if (n <= 1) return {1}; 

        vector<int> result = {1};

        for (int i = 2; i <= n; ++i) {
            result = multiply(i, result); 
        }

        return result;
    }
};
