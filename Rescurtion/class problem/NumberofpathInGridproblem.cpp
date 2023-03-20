#include<iostream>
using namespace std;
int f(int i,int j,int m,int n){
    if(i>=m and j>=n) return 0;
    if(i==m-1 or j==n-1) return 1;
    return f(i+1,j,m,n)+f(i,j+1,m,n);
    
}
int main(){
    //size of grid is m,n
    int m=3,n=3;
    int result =f(0,0,m,n);
   cout<<result;
    return 0;
}
