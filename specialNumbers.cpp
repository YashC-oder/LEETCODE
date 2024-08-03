class Solution {
private:
    vector<int> specialNumbers;
    
    void precomputeSpecialNumbers(int maxNum) {
        int maxRoot = static_cast<int>(sqrt(maxNum)) + 1;
        vector<bool> isPrime(maxRoot + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= maxRoot; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxRoot; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for (int i = 2; i <= maxRoot; ++i) {
            if (isPrime[i]) {
                int square = i * i;
                if (square <= maxNum) {
                    specialNumbers.push_back(square);
                }
            }
        }
    }
    
    int countSpecialNumbersInRange(int l, int r) {
        return upper_bound(specialNumbers.begin(), specialNumbers.end(), r) -
               lower_bound(specialNumbers.begin(), specialNumbers.end(), l);
    }
    
public:
    int nonSpecialCount(int l, int r) {
        precomputeSpecialNumbers(r);
        
        int totalCount = r - l + 1;
        
        int specialCount = countSpecialNumbersInRange(l, r);
        
        return totalCount - specialCount;
    }
};