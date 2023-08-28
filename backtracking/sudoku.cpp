#include <iostream>
#include <vector>
 
 
using namespace std;
 
 
const int SIZE = 9;
 
/* Takes a partially filled-in grid and  tries
    to assign values to all unassigned locations in
    such a way to meet the requirements for
    Sudoku solution */
bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
 /*if we have reached the 8th
           row and 9th column (considering 0
           indexed matrix) ,
           Return true as no further backtracking is required      */
    if (row == SIZE) {
        for(int i = 0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                cout<<grid[i][j]<<"  ";
            }
            cout<<endl;
        }
        
        return true; // all rows filled
    }
// Check if column value  becomes 9 ,
        // move to next row
        // and make column =0
    if (col == SIZE) {
        return solveSudoku(grid, row + 1, 0); // move to next row
    }
// Check if the current position
        // of the grid already
        // contains value >0, we iterate
        // for next column
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1); // move to next column
    }
    for (int num = 1; num <= 9; num++) {
        bool valid = true;
        // check row
        for (int c = 0; c < SIZE; c++) {
            if (grid[row][c] == num) {
                valid = false;
                break;
            }
        }
        // check column
        if (valid) {
            for (int r = 0; r < SIZE; r++) {
                if (grid[r][col] == num) {
                    valid = false;
                    break;
                }
            }
        }
        // check subgrid
        if (valid) {
            int subgridRow = row / 3 * 3;
            int subgridCol = col / 3 * 3;
            for (int r = subgridRow; r < subgridRow + 3; r++) {
                for (int c = subgridCol; c < subgridCol + 3; c++) {
                    if (grid[r][c] == num) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    break;
                }
            }
        }
        if (valid) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0; // backtrack
        }
    }
    return false; // no solution found
}
 
int main()
{
    vector<vector<int>> board={
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    int res = solveSudoku(board,0,0);
    cout<<"Ans is "<<res;

    return 0;
}
