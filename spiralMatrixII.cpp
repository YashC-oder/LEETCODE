#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));

        int startRow = 0 , startCol = 0;
        int endRow = n-1, endCol = n-1;
        int num = 1;

       while (startRow <= endRow && startCol <= endCol) {
            for (int i = startCol; i <= endCol; i++) {
                matrix[startRow][i] = num++;
            }
            startRow++;

            for (int i = startRow; i <= endRow; i++) {
                matrix[i][endCol] = num++;
            }
            endCol--;

            for (int i = endCol; i >= startCol; i--) {
                matrix[endRow][i] = num++;
            }
            endRow--;

            for (int i = endRow; i >= startRow; i--) {
                matrix[i][startCol] = num++;
            }
            startCol++;
        }

        return matrix;
    }
};

int main(){
    Solution s;
     vector<vector<int>> matrix = s.generateMatrix(3);

     for(const auto& vec : matrix){
        for(const int& i : vec){
            cout << i << " ";
        }
        cout<< endl;
     }
}