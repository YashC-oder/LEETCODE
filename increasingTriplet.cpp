class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
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
