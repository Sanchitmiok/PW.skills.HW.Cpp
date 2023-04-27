#include<iostream>
#include<vector>
using namespace std;
int searching_index_rotated_sorted(vector<int> a,int target){
     int low=0,high=a.size();int pivot;
     //first of all we need to find out the idex where two diff sorted arr are formed
     //eg 4,5,1,2,3 here 4,5 are sorted and 1,2,3 are sorted now here pivoted index is 2
     while(low<=high){
      int mid=(low+high) /2;
      if(a[mid]<=a[a.size()-1]){
        pivot=mid;
       high=mid-1;
      
      }else low=mid+1;
     }
     if(a[a.size()-1]>target){
       low=pivot,high=a.size()-1;
}else low=0,high=pivot-1;
while (low<=high){int mid=(low+high)/2;
  if(a[mid]==target) return mid;
  else if(a[mid]>target) high=mid-1;
  else low=mid+1;
}
return -1;
}
int main(){
vector<int> a={18,19,20,22,3,4,5,6,10};
int target=4;
cout<<searching_index_rotated_sorted(a,target);
  return 0;
}
