class Solution {
private:
    pair<int,int> countMinMax(vector<int>& rating,int start ,int end,int target){
        int countMin = 0;
        int countMax = 0;
        for(int i = start;i<end;i++){
            if(rating[i] < target){
                countMin++;
            }else{
                countMax++;
            }
        }
        return {countMin,countMax};
    }
public:
    int numTeams(vector<int>& rating) {
        int size = rating.size();
        int count = 0;

        for(int i = 0;i<size;i++){
            int current = rating[i];
            auto[rightMin,rightMax] = countMinMax(rating,i+1,size,current);
            auto[leftMin,leftMax] = countMinMax(rating,0,i,current);
            count += ( leftMin * rightMax ) + ( leftMax * rightMin );
        }

        return count;
    }
};