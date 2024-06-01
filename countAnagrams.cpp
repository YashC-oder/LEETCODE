class Solution {
private:
    const int MOD = 1000000007;
    vector<long long> factorials;
    vector<long long> invFactorials;

    void computeFactorials(int n) {
        factorials.resize(n + 1);
        invFactorials.resize(n + 1);
        factorials[0] = 1;

        for (int i = 1; i <= n; ++i) {
            factorials[i] = (factorials[i - 1] * i) % MOD;
        }

        invFactorials[n] = modPow(factorials[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i) {
            invFactorials[i] = (invFactorials[i + 1] * (i + 1)) % MOD;
        }
    }

    long long modPow(long long base, int exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int permutation(const string &word) {
        int length = word.size();
        unordered_map<char, int> frequency;
        for (const char ch : word) {
            frequency[ch]++;
        }

        long long product = 1;
        for (const auto &pair : frequency) {
            product = (product * invFactorials[pair.second]) % MOD;
        }

        return (factorials[length] * product) % MOD;
    }

public:
    int countAnagrams(string s) {
        int maxWordLength = s.size();
        computeFactorials(maxWordLength);

        stringstream words(s);
        string word;
        long long result = 1;

        while (words >> word) {
            result = (result * permutation(word)) % MOD;
        }

        return result;
    }
};