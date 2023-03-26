#include<iostream>//its complex code,better to see its dry run again''
using namespace std;
int partition(int arr[],int first,int last){
    int pivot=arr[last];
    int i=first-1;
    int j=first;
  for(j;j<last;j++){
    if(arr[j]<pivot)
    {i++;
    swap(arr[i],arr[j]);}
  }
  swap(arr[i+1],arr[last]/*Dont put pivot dirctly*/);
  return i+1;
}
void quick_sort(int arr[],int first,int last){
    //base  case
    if(first>=last) {return;}
    int pi=partition(arr,first,last);
    quick_sort(arr,first,pi-1);
    quick_sort(arr,pi+1,last);
}
int main(){
    int arr[]={20,12,35,16,18,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    quick_sort(arr,0,n-1);
     cout<<"After sorting :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
