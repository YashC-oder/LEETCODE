#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
#define MOD 998244353
#define ll long long

ll F(ll num1, ll num2) {
    int size = floor(log10(num2)) + 1;
    return (num1 * pow(10,size) + num2);
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size, 0);

    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    ll sum = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            sum += F(nums[i], nums[j]);
        }
    }

    cout << sum % MOD;

    return 0;
}
