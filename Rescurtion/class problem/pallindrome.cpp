#include<iostream>
using namespace std;
int fun(int n,int*temp){
    if(n>=0 and n<=9){
        int lastD=(*temp)%10;
        (*temp)/=10;
        return (n==lastD);
    }
    bool result= (fun(n/10,temp)and (n%10==(*temp)%10));
    *temp/=10;
    return result;
}
int main(){
int n=131;
int temp=n;
int result =fun(n,&temp);
cout<<(result==0?"its not a palindrome ":"its a pallindrome ");
    return 0;
}
