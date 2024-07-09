class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();

        vector<pair<int,int>> pos_speed;
        for(int i = 0; i < size; i++){
            pos_speed.push_back({position[i], speed[i]});
        }
        sort(pos_speed.begin(), pos_speed.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });

        stack<double> st;
        for(const auto& data : pos_speed){
            auto [pos, velo] = data;
            double time = (double)(target - pos) / velo;
            if(!st.empty() && time <= st.top()){
                continue;
            }
            st.push(time);
        }
        return st.size();
    }
};
