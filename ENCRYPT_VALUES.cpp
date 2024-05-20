#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    
    vector<long> result;
    
    while (testCases--) {
        int size;
        cin >> size;
        
        vector<int> numbers(size);
        for (int i = 0; i < size; ++i) {
            cin >> numbers[i];
        }
        sort(numbers.begin(), numbers.end());
        
        long s = 0;
        
        for (int num : numbers) {
            s = max(s + num, s * num) % 1000000007;
        }
        
        result.push_back(s);
    }
    
    for (long res : result) {
        cout << res << endl;
    }

    return 0;
}
