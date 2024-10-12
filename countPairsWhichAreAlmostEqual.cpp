class Solution {
private:
    bool almostEqual(int num1, int num2) {
        string num_one = to_string(num1);
        string num_two = to_string(num2);
        
        int size = max(num_one.size(), num_two.size());
        while (num_one.size() < size) {
            num_one = '0' + num_one;
        }
        while (num_two.size() < size) {
            num_two = '0' + num_two;
        }
 
        int mismatchCount = 0;
        int firstMismatch = -1, secondMismatch = -1;
        
        for (int i = 0; i < size; i++) {
            if (num_one[i] != num_two[i]) {
                mismatchCount++;
                if (mismatchCount > 2) return false;
                
                if (firstMismatch == -1) {
                    firstMismatch = i;
                } else {
                    secondMismatch = i;
                }
            }
        }
        
        if (mismatchCount == 2) {
            swap(num_one[firstMismatch], num_one[secondMismatch]);
        }
        
        return num_one == num_two;
    }

public:
    int countPairs(vector<int>& nums) {
        int size = nums.size();
        int count = 0;

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (almostEqual(nums[i], nums[j])) {
                    // cout << nums[i] << " " << nums[j] << " " << "true" << endl;
                    count++;
                } 
                // else {
                //     cout << nums[i] << " " << nums[j] << " " << "false" << endl;
                // }
                // cout << count << endl << endl;
            }
        }

        return count;
    }
};
