class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        vector<int> prefix(size + 1, 0);
        
        for (int i = 0; i < size; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        int count = 0;
        
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                for (int k = j; k < size; ++k) {
                    if (prefix[i] == prefix[k + 1]) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};

/*---------------------------------------------------------*/
/// -> O(N) 2ms
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int size = arr.size();
        vector<int> prefix(size + 1, 0);

        for (int i = 0; i < size; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }

        int count = 0;
        for (int i = 0; i < size; ++i) {
            for (int k = i + 1; k < size; ++k) {
                if (prefix[i] == prefix[k + 1]) {
                    count += (k - i);
                }
            }
        }

        return count;
    }
};
