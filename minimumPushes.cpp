class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<int> pq;
        vector<int> counts(26, 0);

        for(char ch : word){
            counts[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(counts[i] > 0) {
                pq.push(counts[i]);
            }
        }

        int count = 1;
        int minPush = 0;

        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            minPush += top * static_cast<int>(ceil(static_cast<float>(count) / 8.0));
            count++;
        }
        return minPush;  
    }
};


class Solution {
public:
    int minimumPushes(string word) {
        vector<int> counts(26, 0);
        for (char ch : word) {
            counts[ch - 'a']++;
        }
        sort(counts.begin(), counts.end(), greater<int>());

        int count = 1;
        int minPush = 0;

        for (int i = 0; i < 26 && counts[i] > 0; ++i) {
            minPush += counts[i] * static_cast<int>(ceil(static_cast<float>(count) / 8.0));
            count++;
        }

        return minPush;
    }
};