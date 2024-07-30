class Solution {
public:
    int minimumDeletions(string s) {
        int size = s.size();
        vector<int> numA(size,0);
        for(int i = size-1,count = 0;i>=0;i--){
            numA[i] = count;
            if(s[i] == 'a') count++;
        }
        int minOp = INT_MAX;
        for(int i = 0,count = 0;i<size;i++){
            minOp = min(minOp,numA[i]+count);
            if(s[i] == 'b') count++;
        }

        return minOp;
    }
};