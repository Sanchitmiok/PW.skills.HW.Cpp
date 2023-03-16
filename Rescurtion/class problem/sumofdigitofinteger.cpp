// Problem 1 Given an integer find out  the sum of digit using recursion;
// Input n= 1234
// Output 10
// Explanation 1+2+3+4=10
#include <iostream>
using namespace std;
int fun(int n){
    if(n<=9){
        return n;
    }
        int result=n%10+fun(n/10);
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
