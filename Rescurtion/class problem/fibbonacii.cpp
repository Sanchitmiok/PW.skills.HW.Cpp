// Problem 2: Write a Program to find nth fibonacci number.
#include <iostream>
using namespace std;
int fun(int n){
    if(n==0){
        return 0;;
    }
    else if (n==1) return 1;
    int result=fun(n-1)+fun(n-2);
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
