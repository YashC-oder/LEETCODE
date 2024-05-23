class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        int size = points.size();
        vector<pair<int,int>> intersect;
        intersect.push_back({points[0][0],points[0][1]});
        for(int i = 1 ; i < size ; i++){
            if(intersect.back().second >= points[i][0]){
                intersect.back().first = max(intersect.back().first,points[i][0]);
                intersect.back().second = min(intersect.back().second,points[i][1]);
            }else{
                intersect.push_back({points[i][0],points[i][1]});
            }
        }
        return intersect.size();
    }
};