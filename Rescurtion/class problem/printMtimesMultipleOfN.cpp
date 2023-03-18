#include<iostream>
using namespace std;
void fun(int n,int j,int m){
    if(j>m) return;
    cout<<n*j<<" ";
    fun(n,j+1,m);
}
int main(){
    int n,m;
    cin>>n>>m;
    fun(n,1,m);
    return 0;
}
