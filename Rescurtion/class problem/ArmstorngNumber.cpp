//arm strong number means let num=153
//number of digit is 3 so the sum of idividual number to the power digit should equal to
// number itself 
// 1^3+5^3+3^3=1+125+9=153;
#include<iostream>
using namespace std;
double pow(int a,int b){
double result=1;
for(int i=0;i<b;i++){
    result*=a;
}
return result;
}
int fun(int n,int d){
    if(n==0) return 0 ;
    return pow(n%10,d)+fun(n/10,d);
}
int main(){
    int n;
    cin>>n;
    int tem=n;
    int d=0;
    while(tem>0){
        d++;
        tem/=10;
    }
    int result=fun(n,d);
    if(result==n){
        cout<<"Yes its a armstrong number :)";
    } else  cout<<"No its not a armstrong number :)";
    return 0;
}
