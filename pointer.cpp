
#include<iostream>
using namespace std;
int swap(int *ada,int*adb){
     int temp=*ada;
     *ada=*adb;
     *adb=temp;
    
}
int main(){
int a,b;
   cin>>a>>b;
   cout<<"a="<<a<<"  b="<<b<<endl;
int *ada=&a;
int *adb=&b;
   swap(&a,&b);
   cout<<"a="<<a<<"  b="<<b<<endl;

    return 0 ;
}

