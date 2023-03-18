#include<iostream>
using namespace std;
int gcd(int n,int m){
    if(m>n) return gcd(m,n);
    if(m==0) return n;
    return gcd(m,n%m);
}
int main(){
    int n,m;
    cin>>n>>m;
    int result =gcd(n,m);
    cout<<result;
    return 0;
}
