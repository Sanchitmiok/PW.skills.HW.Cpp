#include <iostream>
using namespace std;
int fun(int* a,int id,int n){
     if (id==n-1) {
        return a[n-1];
     }
      return a[id]+fun(a,id+1,n);
}
int main(){
    int n=4;
int a[]={2,3,1,8};
cout<<fun(a,0,n);
return 0;
}
