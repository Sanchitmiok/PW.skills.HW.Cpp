#include<iostream>
#include<vector>
using namespace std;

bool canweplace(int row , int col , vector<vector<char>> &grid){
    for(int i = row - 1 ; i>=0 ; i--){
        if(grid[i][col]=='Q'){
            return false;
        }
    }
    for(int i = row - 1 ,j=col-1; i>=0 and j>=0; j--,i--){
        if(grid[i][j]=='Q'){
            return false;
        }
    }
    for(int i = row - 1,j=col+1 ; j<grid.size() and i>=0 ; i--,j++){
        if(grid[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void nqueen(int row ,int n , vector<vector<char>> &grid){
    if(row==n){
        for(int i = 0 ; i<row;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n**\n";
    }
    for(int col=0 ; col<n ; col++){
        if(canweplace( row ,  col , grid)){
         grid[row][col] = 'Q';
         nqueen(row+1,n,grid);
         grid[row][col] ='.';
        }
    }
}
int main()
{   
    vector<vector<char>> grid ( 4 , vector<char> (4,'.') );
    nqueen(0,4,grid);
    return 0;
}
