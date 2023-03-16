#include <iostream>
using namespace std;
void fun(int* a,int id,int n){
    if(id==n)        return;
        cout<<a[id]<<" ";
    fun(a,id +1,n);
}
int main(){
    int n=4;
int a[]={2,3,5,6};

fun(a,0,n);
return 0;
}
