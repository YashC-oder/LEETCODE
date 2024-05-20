#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    vector<int> a, b, c;

    int countC(int i, int j, int k) {
        if (i >= a.size() || j >= b.size() || k < 0) {
            return 0;
        }
        
        
        while (j < b.size() && b[j] < a[i]) {
            j++;
        }
        if(j == b.size() || b[j] > c[k]) return 0;
        
        int removeA = 1 + countC(i + 1, j, k);
        
        int removeC = 1 + countC(i, j, k - 1);
        
        int cult = min(removeA, removeC);
        
        
        return cult;
    }

public:
 int minOperation(string str,int length){
    for (int i = 0; i < length; i++) {
            if (str[i] == 'a') {
                a.push_back(i);
            } else if (str[i] == 'b') {
                b.push_back(i);
            } else if (str[i] == 'c') {
                c.push_back(i);
            }
        }

        int minOP = 0;
        for(int i = 0;i<b.size();i++){
            minOP = min(minOP,countC(i));
        }
        return minOP;
    }
};


int main() {
    int testcases;
    cin >> testcases;
    
    while (testcases--) {
        int length;
        cin >> length;
        string str;
        cin >> str;
        

        Solution sol;

        cout << sol.minOperation(str,length) << endl;
    }
    
    return 0;
}



/*------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;

    string s;

    cin >> n >> s;

    long long countC = 0;
    long long c = 0;
    long long count = INT_MAX;

    vector<int> prefix(n, 0);

    for (long long i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            prefix[i] = 1;

        if (i > 0)
            prefix[i] += prefix[i - 1];
    }

    for (long long i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'c')
            countC++;

        if (s[i] == 'b')
        {
            count = min(count, c + prefix[i]);
            c = countC;
        }
    }

    count = min(count, c);

    cout << count << endl;
}

int main()
{
    long long testcases;
    cin >> testcases;
    while (testcases--)
        solve();
    return 0;
}