#include<iostream>
using namespace std;
int multiple(int a,int b){
    int ans;
 //base  
 if(b==0) return 0;
 ans=a+multiple(a,b-1);
 return ans;
}
int main(){
    int a=5 ,b=3;
    int ans=multiple(a,b);
    cout<<"The multiple of "<<a<<" and "<<b<<" is "<<ans;
    return 0;
}
