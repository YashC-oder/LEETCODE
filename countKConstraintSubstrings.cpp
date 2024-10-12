class Solution {
public:
// tle only in last case
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) 
    {
        long long size = s.size(),left,right,one=0,zero=0,current,i,length;
        vector <long long> result,pre(size+1),dp(size);
        left = 0;
        for(right=0;right<size;right++){
            s[right] == '1' ? one++ : zero++;
            while(zero > k && one > k){
                s[left] == '1' ? one-- : zero--;
                left++;
            }
            current = right - left + 1;
            dp[right] = current;
            pre[right + 1] = pre[right] + dp[right];
        }
        for(auto &query : queries){
            left = query[0];
            right = query[1];
            current = 0;
            length = 0;
            for(i=left;i<=right;i++){
                length++;
                if(dp[i] <= length){
                    current += pre[right+1] - pre[i];
                    break;
                }else{
                    current += length;
                }
            }
            result.push_back(current);
        }
        return result;
    }
};