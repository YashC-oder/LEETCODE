class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        for (const int& num : nums) {
            if (num <= num1) {
                num1 = num;
            } else if (num <= num2) {
                num2 = num;
            } else {
                return true;
            }
        }

        return false;
    }
};
