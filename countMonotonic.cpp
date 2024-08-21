#include<vector>
#include<iostream>
using namespace std;

class Solution {
private:
    int modulo = 1e9 + 7;
public:
    int countOfPairs(vector<int>& nums) {
        int size = nums.size();

        vector<vector<int>> dp(size, vector<int>(51, 0));
        for (int i = 1; i <= nums[0]; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < size; i++) {
            for (int current = 0; current <= nums[i]; current++) {
                dp[i][current] = dp[i-1][current]; 
                for (int prev = 0; prev < 51 ; prev++) {
                    if(prev <= current && (nums[i] - current <= nums[i-1] - prev)){
                        dp[i][current] = (dp[i][current] + dp[i-1][prev]) % modulo;
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < 51; i++) {
            count = (count + dp[size-1][i]) % modulo;
        }

        return count;
    }
};

int main(){
    Solution s;
    vector<int> input = {5,5,5,5};
    cout << s.countOfPairs(input) << endl;
    cout << "Execution Finished";
    return 0;
}
