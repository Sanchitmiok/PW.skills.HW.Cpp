#include<iostream>
#include<vector>
using namespace std;
vector<int> searching(vector<int> a,int target){
    int l=a.size()-1;
    int f=0;int first=-1;
    while(f<=l){
        int mid=f+(l-f)/2;
        if(a[mid]==target){
            first=mid;
            l=mid-1;
        }else if(a[mid]>target){
          l=mid-1;
        }else f=mid+1;
    }
    if(first==-1) return {-1,-1};
     l=a.size()-1;
     f=0; int last=-1;
    while(f<=l){
     int mid=f+(l-f)/2;
     if(a[mid]==target) {
        last=mid;
        f=mid+1;
     } else if(a[mid]<target) f=mid+1;
     else l=mid-1;
    }
    return {first,last};
}
int main(){
    vector<int> a={2,3,3,3,4,4,4,4,5};
  vector<int> b=searching(a,4);
  cout<<b[0]<<","<<b[1];
    return 0;
}
