class Solution {
private:
    double distanceSq(vector<int>& p1,vector<int>& p2){
        return (pow(p2[0]-p1[0],2) + pow(p2[1]-p1[1],2));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        unordered_set<double> distances;
        distances.insert(distanceSq(p1,p2));
        distances.insert(distanceSq(p1,p3));
        distances.insert(distanceSq(p1,p4));
        distances.insert(distanceSq(p4,p2));
        distances.insert(distanceSq(p4,p3));
        distances.insert(distanceSq(p3,p2));

        double side     = INT_MAX;
        double diagonal = INT_MIN;

        if(distances.size() != 2){
            return false;
        }

        for(const double& sides : distances){
            side     = min(side,sides);
            diagonal = max(diagonal,sides);
        }

        if(2*side != diagonal) return false;

        return true;
    }
};