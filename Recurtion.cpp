#include<iostream>
using namespace std;
int fun(int p ,int  q){
    if(q==0) return 1;
    if(q==1) return p;
    return (fun(p,q-1) *p);
    

}
int main(){

int p,q;
cout<<"enter p and q :"<<endl;
cin>>p>>q;
cout<<p <<" and "<<q<<endl;
int result =fun(p,q);
cout<<"the p^q is : "<<result;
    return 0;
}
