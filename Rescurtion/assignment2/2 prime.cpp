#include<iostream>
using namespace std;
int prime(int n,int l){
    //base case
    if(l>n) return 0;
    int count=0;
    if(n%l==0){
        count=1;
    }
    int x=count+prime(n,l+1);
    return x;
}
int main(){
    int n=98;
    int val=prime(n,1);
    if(val==2){
        cout<<"Yes";
    }else cout<<"No";
    return 0;
}
