class Solution {
private:
    int size;
    bool isSafe(int row, int col, vector<vector<int>>& board) {
        // Check row and columns
        for (int i = 0; i < size; ++i)
            if (board[i][col] == 1|| board[row][i] == 1) return false;

        // Check diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 1) return false;
        
        for (int i = row, j = col; i < size && j < size; ++i, ++j)
            if (board[i][j] == 1) return false;

        for (int i = row, j = col; i >= 0 && j < size; --i, ++j)
            if (board[i][j] == 1) return false;
        
        for (int i = row, j = col; i < size && j>=0; ++i, --j)
            if (board[i][j] == 1) return false;
        
        return true;
    }

    void PossibleStates(vector<vector<int>>& board,int& ans,int n,int row = 0){
        if(n == 0){
            ans++;
            return;
        }
        if(row >= size) return;
        for(int col = 0 ; col < size;col++){
            if(isSafe(row,col,board)){
                board[row][col] = 1;
                PossibleStates(board,ans,n-1,row+1);
                board[row][col] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        size = n;
        vector<vector<int>> board(n,vector<int>(n,0)); // 0 empty and 1 queen
        int ans = 0;

        PossibleStates(board,ans,n);

        return ans;
    }
};