#include<iostream>
using namespace std;
#include<vector>
void fun(string &st,int i,string res,vector<string> &v){
    if(i==st.length()){
         v.push_back(res);
         return;
    }
    fun(st,i+1,res,v);
    fun(st,i+1,res+st[i],v);
}
int main(){
    vector<string> v;
    string str="sbd";
    fun(str,0,"",v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";// s b d sb bd sd sbd " "
    }
    return 0;
}
