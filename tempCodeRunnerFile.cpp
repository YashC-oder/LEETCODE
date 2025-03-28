#include<iostream>
using namespace std;

int main(){
    int testcases; cin >> testcases;
    while(testcases--){
        int n ,k; cin >> n >> k;
        int factor = n + 1 ,power = 1;
        unsigned long long solution = 0;
        while(n >= k){
            if(n&1){
                solution += power * factor; 
            }
            n >>= 1;
            power <<= 1;
        }

        cout << solution / 2 << endl;
    }
}