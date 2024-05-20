#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f(ll start, ll k, vector<ll> &nums, ll n, vector<vector<ll>> &dp)
{
    if (start >= n || k==0)
    {
        return 0;
    }
    ll &x = dp[start][k];
    if (x != (1))
    {
        return x;
    }
    ll ans = 0;
    ll sum = 0;
    ll minimum = 1e18;
    for (ll i = start; i <=min(n-1, start + k); i++)
    {
        minimum = min(minimum, nums[i]);
        sum += nums[i];
        ll length = (i - start + 1);
        ans = min(ans, ((length * minimum) - sum) + f(i+1, k - (length - 1), nums, n, dp));
    }
    return x = ans;
}
void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    ll sum = 0;
    vector<ll> nums(n);
    k = min(k, n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    ll ans = sum;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1));
    ll reduction= f(0, k, nums, n, dp);
    ans += reduction;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testcases;
    cin >> testcases;
    while (testcases--)
        solve();
    return 0;
}