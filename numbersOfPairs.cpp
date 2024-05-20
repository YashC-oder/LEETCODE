class Solution {
private:
    bool isValid(const vector<vector<int>>& points, int i, int j) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        
        if (x1 <= x2 && y1 >= y2) {
            for (int index = i + 1; index < j; index++) {
                int x3 = points[index][0], y3 = points[index][1];
                if (x3 >= x1 && x3 <= x2 && y3 >= y2 && y3 <= y1) {
                    return false;
                }
            }
            return true;
        }
        
        return false;
    }

public:
    int numberOfPairs(vector<vector<int>>& points) {
        int size = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] > b[1]; 
            }
        });

        int count = 0;

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (isValid(points, i, j)) {
                    count++;
                }
            }
        }

        return count; 
    }
};
