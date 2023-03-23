#include<iostream>
using namespace std;
void fun(int n,int*r,int i,int k){
    if(*r==0 || *r<0) return;
    *r=n-k*i; cout<<*r<<" ";
    fun(n,r,i+1,k);
    if(i!=0){*r+=5; cout<<*r<<" ";//to avoid extra number during i=0;
            }
}
int main(){
    int n =10;
    int r=n;int k;
    fun(n,&r,0,5);
    return 0;
}
