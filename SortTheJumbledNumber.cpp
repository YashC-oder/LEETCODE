class Solution {
private:
    int mapNum(int num , vector<int>& mapping){
        if(num == 0) return mapping[0];
        int newNum = 0;
        int factor = 1;
        while(num){
            int index = num%10;
            num = num/10;
            newNum += factor * mapping[index];
            factor *= 10; 
        }
        return newNum;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int size = nums.size();
        vector<int> indexes(size);
        for(int i = 0;i<size;i++){
            indexes[i] = i;
        }

        sort(indexes.begin(),indexes.end(),[&](int& i ,int& j){
            int mappedi = mapNum(nums[i],mapping);
            int mappedj = mapNum(nums[j],mapping);
            if(mappedi == mappedj){
                return i < j;
            }
            return mappedi < mappedj;
        });

        vector<int> newArr(size);
        for(int i = 0;i<size;i++){
            newArr[i] = nums[indexes[i]];
        }

        return newArr;
    }
};