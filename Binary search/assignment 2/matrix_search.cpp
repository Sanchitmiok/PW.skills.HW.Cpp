#include<iostream>
#include<vector>
using namespace std;
bool search_matrix(vector<vector<int>> &v,int target){
    int n=v.size(),m=v[0].size(),first=0;
    int last=m*n-1;
    while(first<=last){
        int mid=first+(last-first)/2;
        int x=mid/m;   //  important step .....
        int y=mid%m;
       int  value=v[x][y];
       if(value==target) 
          return true;
       else if(value<target)
          first=mid+1;
       else
          last = mid - 1;

    }
    return false;
}
int main(){
    vector<vector<int>> v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 30;
    cout<<search_matrix(v,target);
    return 0;
}
