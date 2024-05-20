class Solution {
public:

    void generate(vector<int> nums,vector<vector<int>>& result,vector<int> current,int start = 0){

        result.push_back(current);

        for(int i = start ; i < nums.size() ; i++){
            current.push_back(nums[i]);
            generate(nums,result,current,i+1);
            current.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {

       vector<vector<int>> result;
       vector<int> current;

       generate(nums,result,current);

       return result; 
    }
};