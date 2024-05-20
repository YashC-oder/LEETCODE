#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        const int MOD = 1000000007;
        
        int size = nums.size();
        long long sum = 0;
        long long minVal = INT_MAX;
        long long maxVal = 0;
        
        for (int num : nums) {
            sum += num;
            minVal = min(minVal, (long long)num);
            maxVal = max(maxVal, (long long)num);
        }
        
        long long minCost = LLONG_MAX;
        
        for (long long target = maxVal; target <= 2 * maxVal; target++) {
            long long totalOp = target * size - sum;
            
            long long cost;
            if (2 * cost1 <= cost2) {
                cost = totalOp * cost1;
            } else {
                long long last = totalOp - (target - minVal); 
                if (last < target - minVal) {
                    cost = (target - minVal - last) * cost1 + last * cost2;
                } else {
                   cost = cost2 * (totalOp / 2) + cost1 * (totalOp % 2);
                }
            }
            
            minCost = min(minCost, cost);
        }
        
        return minCost % MOD;
    }
};
