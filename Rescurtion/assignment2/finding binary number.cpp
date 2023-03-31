#include<iostream>
using namespace std;
int fun(int n){
    if(n==0) return 0;//base case::
    int num=n%2+10*fun(n/2);
    return num;
}
int main(){
    int n=10;
    int num=fun(n);
    cout<<num;
}
