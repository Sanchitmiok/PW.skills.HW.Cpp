// Problem 2 Given two numbers a & b, find the value a^b using a recursive functions
#include <iostream>
using namespace std;
int fun(int a,int b){
    if(b==1){
        return a;
    }
        int result=a*fun(a,b-1);
   return result;
}
int  main(){
 int a,b;
 cout<<"Pls enter the num ";
 cin>>a>>b;;
 int result =fun(a,b);
 cout<<result;
    return 0;
}
