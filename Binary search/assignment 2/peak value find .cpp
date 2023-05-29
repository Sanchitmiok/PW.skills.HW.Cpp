#include<iostream>
#include<vector>
using namespace std;
int search_peakvalue(vector<int> &arr){
    int last=arr.size()-1;
    int first=0;int mid=first+(last-first)/2;
    if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1] ) return mid;// lies in first part of the mountain where values is increasing
    else if (arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){// values after the peak value ..
        first=mid+1;
    } else last=mid-1;
}
int main(){
    vector<int> arr={0,4,1,0};
    cout<<search_peakvalue(arr);
}
