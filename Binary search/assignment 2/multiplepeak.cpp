#include<iostream>
#include<vector>
using namespace std;
int search_peakvalue(vector<int> &a){
    int n=a.size();int low=0,high=n-1;
    
    if(n==1) return 0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid==0){
            if(a[mid]>a[mid+1]) return 0;
            else return 0;
        }
        else if(mid==n-1){
            if(a[n-1]>a[n-2]) return n-1;
            else return n-2;
        } else {
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return mid;
            else if(a[mid]>a[mid-1]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr={1,2,1,2,6,10,3};
    cout<<search_peakvalue(arr);
    return 0;
}
