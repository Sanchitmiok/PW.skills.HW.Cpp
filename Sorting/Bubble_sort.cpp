#include<iostream>
#include<vector>
using namespace std;
void bubble_sort(vector<int> &v){
    int n=v.size();
    for(int i=0;i<v.size()-1;i++){//we treverse just n-1 times
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1])
            swap(v[j],v[j+1]);
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
    bubble_sort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
