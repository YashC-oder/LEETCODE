class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        vector<int> count(size+1,0);

        for(const int& i : citations){
            if(i > size){
                count[size]++;
            }else{
                count[i]++;
            }
        }
        int h_index = size;
        int papers = 0;
        for(;h_index>=0;h_index--){
            papers += count[h_index];
            if(papers >= h_index) break;
        }

        return h_index;
    }
};