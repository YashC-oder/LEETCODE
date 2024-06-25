class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int size = temperatures.size();
        if(!size) return {};
        vector<int> days(size,0);
        stack<pair<int,int>> st; // {temperature,index}
        for(int i = 0;i<size;i++){
            int current = temperatures[i];
            while(!st.empty() && st.top().first < current){
                days[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({current,i});
        }

        return days;
    }
};