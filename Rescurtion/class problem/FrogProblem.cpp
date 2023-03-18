#include<iostream>
using namespace std;
int fun(int*a,int n,int i){
    if(i==n-1) return 0;
    if(i==n-2) return fun(a,n,i+1)+abs(a[i]-a[i+1]);
    return min((fun(a,n,i+1)+abs(a[i]-a[i+1])),fun(a,n,i+2)+abs(a[i]-a[i+2]));
}
int main(){
    int a[]={10,30,40,20};
    int n=4;
    int result=fun(a,4,0);
    cout<<result;
    return 0;
}
