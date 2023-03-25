#include<iostream>
#include<vector>
using namespace std;
void ins_sort(vector<int> &v){
    for(int i=1;i<v.size();i++){
        int cur_ele =v[i];
        int j=i-1;
        while(j>=0 && v[j]>cur_ele){
            v[j+1]=v[j];
            j--;
        } v[j+1]=cur_ele;
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
    ins_sort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
