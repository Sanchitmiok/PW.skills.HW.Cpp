#include<iostream>
using namespace std;
int fun(int n ,int m){
     if(m==1) return n*(n+1)/2;
    return fun(fun(n,m-1),1);
}
int main(){
    int m=1 ,n=4;
    int sum=fun(n,m);
    cout<<sum;// ans 231

    return 0;
}
