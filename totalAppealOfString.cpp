class Solution {
public:
    long long appealSum(string s) {
        int size = s.size();
        long long sum = 0;
        unordered_set<char> appeared;
        unordered_map<string,long long> dp;
        for(int i = 0;i<size;i++){
            long long count = 0;
            long long prev = 0;
            string sub = s.substr(i,size);
            sort(sub.begin(),sub.end());
            if(dp.find(sub) != dp.end()){
                sum += dp[sub];
                continue;
            }
            string prevChar = "";
            for(int j = i;j<size;j++){
                char current = s[j];
                prevChar += current;
                if(appeared.find(current) == appeared.end()){
                    appeared.insert(current);
                    ++prev;
                }
                count += prev;
            }
            sum += count;
            appeared.clear();
            sort(prevChar.begin(),prevChar.end());
            dp[preChar] = count;
        }
        return sum;
    }
};

// 0ms
class Solution {
public:
    long long appealSum(string s) {
        int size = s.size();
        long long sum = 0;
        vector<int> last_position(26, -1);  // To store the last position of each character
        
        for (int i = 0; i < size; ++i) {
            int current_char_index = s[i] - 'a';
            // Calculate the contribution of the current character to the total appeal
            sum += (i - last_position[current_char_index]) * (size - i);
            // Update the last position of the current character
            last_position[current_char_index] = i;
        }
        
        return sum;
    }
};
