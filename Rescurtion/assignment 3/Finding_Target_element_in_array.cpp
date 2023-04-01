#include<iostream>
#include<vector>
using namespace std;
void fun(int*arr,vector<int> &v,int size,int i,int target){
    if(i>=size ) return ;
    if(arr[i]==target){
        v.push_back(i);
    }
    fun(arr,v,size,i+1,target);
}
int main(){
    int arr[]={2,3,4,3,3,5};//ans should be 1,3,4
    int target=5;
    vector<int> v;int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    fun(arr,v,size,0,target);
    
     for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
