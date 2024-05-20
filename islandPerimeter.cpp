class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<pair<int,int>> direction{{1,0},{-1,0},{0,1},{0,-1}};

        int perimeter = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0 ;i < row ; i++){
            for(int j = 0; j < col ; j++){
                int current = 0;

                if(grid[i][j]){
                    current = 4;
                    for(const auto& dir : direction ){
                        int r = i + dir.first;
                        int c = j + dir.second;

                        if( r < row && r >= 0 && c < col && c >= 0){
                            current -= grid[r][c];
                        }
                    }
                }

                perimeter += current;
            }
        }

        return perimeter;
    }
};