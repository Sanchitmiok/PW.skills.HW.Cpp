// Q1 -Write a program to print the kth element of an array using pointers.
// The first line of the input contains the size of the array and the value of k.
// The second line of input contains the elements of the array. You can assume that 0 <= k < size
// of the array.
#include <iostream>
using namespace std;
int fun(int * arr,int m){
    int *add=arr+m-1;
    cout<<"Mth position element is <<"<<*add;
}
int main()
{   int n,m;   

    cout<<"pls enter the size and number of array :"<<endl;
    cin>>n>>m;
     int arra[n];
     for(int i=0;i<n;i++){
      cin>>arra[i];
     }
     for(int i=0;i<n;i++){
     cout<<arra[i]<<" ";
     }cout<<endl;
    fun(arra,m);
     return 0;
}
