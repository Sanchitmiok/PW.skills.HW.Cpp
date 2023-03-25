#include<iostream>
#include<vector>
using namespace std;
void put_all_zero_at_end(vector<int> &v){
    int n=5;
    for(int i=n-1;i>=0;i--){
        int j=0;bool flag=false;
        while(j!=i){
            if(v[j]==0 && v[j+1]!=0){
                swap(v[j],v[j+1]);
                flag=true;
            }j++;
        }
        if(!flag) break;
    }

    return;
}
int main(){
int n=5;
vector<int> v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
put_all_zero_at_end(v);
for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
}

    return 0;
}
