#include<iostream>
using namespace std;
int fun(int n){
    if(n==0) return 0;
int result =fun(n-1)+((n%2==0)?(-n):n);
    return result;
}
int main(){
    int n;
    cin>>n;
    int result=fun(n);
    cout<<result;
    return 0;
}
