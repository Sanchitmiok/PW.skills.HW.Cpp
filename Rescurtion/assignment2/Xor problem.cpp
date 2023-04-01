#include<iostream>
using namespace std;
int fun(int n){
    //base case 
    if(n==1) return 1;
    int a=n%10;//last remainder
    int b=n/10;
    int c=b%10;//second last remainder:)
    int x;
    if(a==c){
       x=0 ;//if they are equal than return zero 
    } else x=1 ;//elsae return 1 acoording to XOR concept
    int val=x+10*fun(n/10);
    return val;
}
int main(){
    int n=1001;//ans should be::111
    cout<<n<<" -> ";
    int val=fun(n);
    cout<<val;
    return 0;
}
