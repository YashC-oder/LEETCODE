class Solution {
    int solve(vector<int>& sum1,vector<int>& sum2,int totalSum){
        int m = sum1.size(),size = sum2.size();
        int minDiff = INT_MAX;
        for(int i=0;i<m;++i){
            int target = totalSum/2-sum1[i];
            int lb = lower_bound(sum2.begin(),sum2.end(),target)-sum2.begin();
            if(lb==sum2.size())
                minDiff = min(minDiff,abs(totalSum-2*(sum1[i]+sum2[lb-1])));
            else if(lb==0)
                minDiff = min(minDiff,abs(totalSum-2*(sum1[i]+sum2[lb])));
            else
                minDiff = min({minDiff,
                               abs(totalSum-2*(sum1[i]+sum2[lb-1])),
                               abs(totalSum-2*(sum1[i]+sum2[lb]))});
        }
        return minDiff;
    }
public:
    int minimumDifference(vector<int>& nums) {
        int size=nums.size()/2;
        int totalSum = 0;//Sum of array
        vector<int> nums1,nums2;
        //Divide array into 2 halves and find totalSum as well
        for(int i=0;i<size;++i){
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i+size]);
            totalSum += nums[i]+nums[i+size];
        }
        //find all possible sums
        vector<int> sum1[size+1],sum2[size+1];
        // 1<<size == pow(2,size)
        for(int mask=0;mask<(1<<size);++mask){
            int totalSum1 = 0,totalSum2 = 0,count = 0;
            for(int j=0;j<size;++j)
                if(mask&(1<<j)){
                    totalSum1 += nums1[j];
                    totalSum2 += nums2[j];
                    count += 1;
                }
            sum1[count].push_back(totalSum1);
            sum2[count].push_back(totalSum2);
        }
        //Just sort 2nd array (Follow Meet in the middle video)
        for(int i=0;i<=size;++i)
            sort(sum2[i].begin(),sum2[i].end());
        
        int minDiff = INT_MAX;//Assuming large diff value
        for(int i=0;i<=size;++i)
            minDiff = min(minDiff,solve(sum1[i],sum2[size-i],totalSum));
        return minDiff;
    }
};