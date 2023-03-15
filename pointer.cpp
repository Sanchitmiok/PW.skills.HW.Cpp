// Q1 -Write a program to print the kth element of an array using pointers.
// The first line of the input contains the size of the array and the value of k.
// The second line of input contains the elements of the array. You can assume that 0 <= k < size
// of the array.
#include <iostream>
using namespace std;
int main()
{   int n;   
    cout<<"pls enter the size and number of array :"<<endl;
    cin>>n;
     int arra[n];
     for(int i=0;i<n;i++){
      cin>>arra[i];
     }
     for(int i=0;i<n;i++){
     cout<<arra[i]<<" ";
     }cout<<endl;
     int sum=0;
     for(int i=0;i<n;i++){
      int*add=arra;
      sum+=add[i];
      add++;
     }
     cout<<"sum is "<<sum;
     return 0;
}
