//pointer
#include<iostream>
using namespace std;
int maxandmin(int a,int b ,int c,int *smallest){
*smallest=min(a,min(b,c));
return max(a,max(b,c));
}
int main(){
int a;int b;int c;
cin>>a>>b>>c;
int smallest;
int max=maxandmin(a,b,c,&smallest);
cout<<max<<" and "<<smallest;
    return 0 ;
}

