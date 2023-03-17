#include<iostream>
using namespace std;
string fun(string s,int id,int n){
    if(id==n) return "";
    
    string curr="";
    curr+=s[id];
    return ((s[id]=='a')?"":curr)+fun(s,id+1,n);
}
int main(){
    string s="adxvd";
   int n=5;
    string result =fun(s,0,n);
    cout<<result;
    return 0;
}
