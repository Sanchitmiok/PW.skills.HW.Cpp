#include <iostream>
using namespace std;
bool fun(int*a,int x,int i,int n){
    if(i==n) return false;
    // if(a[i]==x){
    //     return true ;
    // } else fun(a,x,i+1,n);
     // we can also use 
     if(i==n) return false;
     return (a[i]==x||fun(a,x,i+1,n));
}
int main(){
int arr[]={2,3,4,5,6};
int x=7;
int n=5;
bool result =fun(arr,x,0,n);
cout<<result<<endl;
if(result ){ cout<<"yes";}//if result is true i.e 1 the if exicute 
else cout<<"No";//if result return 0

    return 0;
}
