#include<iostream>//indexof min element
#include<vector>
using namespace std;
int searching_min_rotated_arr(vector<int> &a){       
        int low=0,high=a.size(); 
        if(a[0]<a[high]) return 0;
        while(low<=high){
      int mid=low+(high-low)/2;
      if(a[mid]>a[mid+1] &&a[mid]>a[mid-1]){
        return mid+1;
    }else if(a[mid]>a[mid-1]&&a[mid]>a[high]){
      low=mid+1;
    }else high=mid-1;

        }
        
} 
int main(){
vector<int> a={22,33,44,55,66};

cout<<"the min element "<<a[searching_min_rotated_arr(a)]<<" is found on "<<searching_min_rotated_arr(a)<<" position::";

  return 0;
}
