#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int main() {
    vector<int> min_cost;
    int testCase;

    cout << "input : " << endl;
    cin >> testCase;
    
    while (testCase--) {
        int size, normal_ball, master_ball;
        cin >> size >> normal_ball >> master_ball;
        
        int cost = 0;
        while (size--) {
            int n;
            cin >> n;
            cost += min(n*normal_ball,master_ball);
        }
        min_cost.push_back(cost);
    }

    cout << "output : " << endl;

    for(const int&i : min_cost){
        cout << i << endl;
    }
    return 0;
}