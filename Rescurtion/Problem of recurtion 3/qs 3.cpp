#include<iostream>
using namespace std;
int count(int n,int val){
    int ans=0;
    if(n==1 && val>=0 ) return 1;
    for(int i=0;i<=val;i++){
       ans+= count(n-1,val-i);
    }
    return ans;
}
int main(){

    int n=2,val=6;
    int ans=count(n,val);
 cout<<ans;
    return 0;
}
