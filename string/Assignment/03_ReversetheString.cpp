#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
string str("OKJIIOK");
int size=str.length();
int flag = 0;
for(int i=0,j=size-1;i<=j;i++,j--){
    char temp=str[i];
    str[i]=str[j];
    str[j]=temp;
}
cout<<str;
    return 0;
}
