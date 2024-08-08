class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int size = rows * cols;
        int row = rStart , col = cStart;
        int L = 1 , R = 1 ;
        bool direction = true;
        vector<vector<int>> indexes;

        indexes.push_back({row,col});
        while(indexes.size() < size){
            for(int i = 0;i<L;i++){
                col += direction ? 1 : -1;
                if(row < rows && col < cols && row >= 0 && col >=0){
                    indexes.push_back({row,col});
                }
            }

            for(int i = 0;i<R;i++){
                row += direction ? 1 : -1;
                if(row < rows && col < cols && row >= 0 && col >=0){
                    indexes.push_back({row,col});
                }
            }

            L++,R++;
            direction = !direction;
        }

        return indexes;
    }
};