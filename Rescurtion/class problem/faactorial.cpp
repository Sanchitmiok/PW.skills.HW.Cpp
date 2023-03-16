// Problem 1-
// Find the value of n!.
#include <iostream>
using namespace std;
int fun(int n){
    if(n==1){
        return 1;
    }
    int result=n*fun(n-1);
   return result;
}
int  main(){
 int n;
 cout<<"Pls enter the num ";
 cin>>n;
 int result =fun(n);
 cout<<result;
    return 0;
}
