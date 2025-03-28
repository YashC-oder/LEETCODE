#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int testcases;
    ios::sync_with_stdio(false);                                               
    cin.tie(NULL);                                                             
    cout.tie(NULL);                                                            
    cout.precision(numeric_limits<double>::max_digits10);
    
    cin >> testcases;
    while (testcases--) {
        int n;
        cin >> n;
        
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
 
        long long currentPrefixSum = 0;
        int maxNonOverlappingZeroSum = 0;
        map<long long, int> prefixIndex;
        vector<int> dp(n + 1, 0); 
        prefixIndex[0] = 0; 
 
        for (int i = 0; i < n; i++) {
            currentPrefixSum += arr[i];
            dp[i + 1] = dp[i];
 
            if (prefixIndex.find(currentPrefixSum) != prefixIndex.end()) {
                int previousIndex = prefixIndex[currentPrefixSum];
                dp[i + 1] = max(dp[i + 1], dp[previousIndex] + 1);
            }
 
            prefixIndex[currentPrefixSum] = i + 1;
        }
        
        cout << dp[n] << endl;
    }
    return 0;
}