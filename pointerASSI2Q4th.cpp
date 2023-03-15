#include <iostream>
using namespace std;
int main()
{
    int n ;
    cin >> n ;
    int a[n][n];
    for( int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
      int*ptr=&a[i][i];
      sum+=*ptr;
    }
   cout<<"The sum of diagonal's are "<<sum;
     
    return 0;
}
 