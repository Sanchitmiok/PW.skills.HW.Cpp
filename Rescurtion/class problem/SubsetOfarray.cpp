#include<iostream>
using namespace std;
#include<vector>
void f(int*arr,int n,int i,vector<int> &v,int sum){
    if(i==n){
        v.push_back(sum);
        return;
    }
    f(arr,n,i+1,v,sum+arr[i]);//when we pick
    f(arr,n,i+1,v,sum);//when we drop 
}
int main(){
    int arr[]={1,2,3};
    int sum =0;
    vector<int> v;
    f(arr,3,0,v,sum);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";// ans should be 0 1 2 3 3  5 4 6
    }
    return 0;
}
