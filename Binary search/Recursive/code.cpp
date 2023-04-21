#include<iostream>
#include<vector>
using namespace std;
int Binary_search_recursive(vector<int> a,int val, int ho,int lo){

    
    if(lo>ho) return -1;
    int mid=lo+(ho-lo)/2;
    if(a[mid]==val) return mid;
    else if(a[mid]<val){
       return Binary_search_recursive(a,val,ho,mid+1);
      } else return Binary_search_recursive(a,val,mid-1,lo);
    

}
int main(){
vector<int> a={2,3,4,5,6,7,8,99,433};
int n=a.size();
cout<<Binary_search_recursive(a,22,n,0);
    return 0;
}
