class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> frequency;

        int count = 0;
        for(int i = 0;i<size;i++){
            int current = nums[i];
            if(frequency[current] < 2){
                nums.push_back(current);
                frequency[current]++;
                count++;
            }
        }

        nums.erase(nums.begin(),nums.begin()+size);

        return count;
    }
};

/*-------------------------------------------------------------------------*/
// better 0ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        for(const int& num : nums)
        {
            if(i==0 || i==1 || nums[i-2] != num)
            {
                nums[i] = num;
                i++;
            }
        }
    return i ;
    }
};