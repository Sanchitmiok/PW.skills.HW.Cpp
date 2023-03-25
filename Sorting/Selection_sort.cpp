#include<iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int> &v){
    for(int i=0;i<v.size()-1;i++){//we treverse just n-1 times

        int min_idx=i;
        for(int j=i+1;j<v.size();j++){
            if(v[min_idx]>v[j]){
                min_idx=j;
            }
        if(min_idx!=i)  swap(v[i],v[min_idx]);
        }
    }
    return ;
}
int main(){
    int n;
      cin>>n;
      vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    selection_sort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
