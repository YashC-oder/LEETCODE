#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_map<int, int> frequency;  // To track frequency of elements
        int operations = 0;

        // Sliding window to analyze each subarray
        for (int i = 0; i < n; ++i) {
            // Include a[i] in the window
            frequency[a[i]]++;

            // Shrink window from the left to maintain a valid subarray
            while (i >= 1 && frequency[a[i]] > 1) {
                frequency[a[i - 1]]--;
                if (frequency[a[i - 1]] == 0) {
                    frequency.erase(a[i - 1]);
                }
                i--;
            }

            // Count operations needed for current subarray
            for (auto& [num, count] : frequency) {
                if (count > 1) {
                    operations += count - 1;  // We need (count - 1) operations to make 'num' unique
                }
            }
        }

        cout << operations << endl;
    }

    return 0;
}
