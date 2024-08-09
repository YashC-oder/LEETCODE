class Solution {
private: 
    bool check(int i, int j, vector<vector<int>>& grid) {
        int sum = 0;

        vector<bool> visited(10, false);
        for(int m = 0; m < 3; m++) {
            for(int n = 0; n < 3; n++) {
                int current = grid[m+i][n+j];
                if(current < 1 || current > 9 || visited[current]) {
                    return false;
                }
                visited[current] = true;
            }
        }

        for(int m = 0; m < 3; m++) {
            sum += grid[i][j+m];
        }


        for(int m = 0; m < 3; m++) {
            int currentRowSum = 0;
            int currentColSum = 0;
            for(int n = 0; n < 3; n++) {
                currentRowSum += grid[m+i][n+j];
                currentColSum += grid[n+i][m+j];
            }
            if(currentRowSum != sum || currentColSum != sum) {
                return false;
            }
        }

        int diagonalLSum = 0, diagonalRSum = 0;
        for(int m = 0; m < 3; m++) {
            diagonalLSum += grid[i+m][j+m];
            diagonalRSum += grid[i+m][j+2-m];
        }

        return (diagonalLSum == diagonalRSum) && (diagonalLSum == sum);
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row < 3 || col < 3) return 0;

        int count = 0;
        
        for(int i = 0; i <= row-3; i++) {
            for(int j = 0; j <= col-3; j++) {
                if(check(i, j, grid)) count++;
            }
        }

        return count;
    }
};
