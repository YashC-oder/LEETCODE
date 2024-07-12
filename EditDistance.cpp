class Solution {
private:
    // recursive solution
    int minDistance(string word1, string word2,int i,int j ,vector<vector<int>>& dp){
        int& result = dp[i][j];
        if(result != -1) return result;
        if(i >= word1.size()){
            return result = size2-j;
        }
        if(j >= word2.size()){
            return result = size1-i;
        }
        if(word1[i] == word2[j]){
            return result = minDistance(word1,word2,i+1,j+1,dp);
        }

        int _insert = minDistance(word1,word2,i,j+1,dp);
        int _delete = minDistance(word1,word2,i+1,j,dp);
        int _replace = minDistance(word1,word2,i+1,j+1,dp);

        return result = 1 + min({_insert,_delete,_replace});
    }
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        vector<vector<int>> dp(size1+1,vector<int>(size2+1,-1));
        // return minDistance(word1,word2,0,0,dp); // using recursive function

        // below is iterative approuch of recursive solution

        for(int i = 0 ;i<=size1;i++){
            dp[i][size2] = size1-i;
        }
        
        for(int i = 0 ;i<=size2;i++){
            dp[size1][i] = size2-i;
        }

        for(int i = size1-1;i>=0;i--){
            for(int j = size2-1;j>=0;j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = 1 + min({dp[i][j+1],dp[i+1,j+1],dp[i+1][j]});
                }
            }
        }

        return dp[0][0];
    }
};