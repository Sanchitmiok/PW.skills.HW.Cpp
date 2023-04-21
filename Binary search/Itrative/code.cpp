#include<iostream>
#include<vector>
using namespace std;
bool fun(vector<int> arr,int value){
    int n=arr.size();
    int first=0;int last =n-1;
    while(first<=last){
        int mid=(first+last)/2;//mid element 
        if(arr[mid]==value){
            return true;
        }else if(arr[mid]<value){//=ignore first half
            first=mid+1;
        }else last=mid-1;//ignore second half
    }
return false;
}
int main(){
vector<int> arr={2,4,5,33,44,233};
cout<<fun(arr,4);
    return 0;
}
