#include <iostream>
#include <vector>
using namespace std;

int fun(vector<int> &v, int n, int m)
{
     if (n <= 0)
          return 0;
     if (n == 1)
          return 1;
     int ways = 0;
     for (int i = 1; i <= m; i++)
     {    if(n-i >= 0) {
          if (v[n - i] != 0)
               ways += v[n - i];
          else
          {
               ways += fun(v, n - i, m);
          }
     }
     }
     v[n] = ways;
     return ways;
}
int countWaysToTop(int n, int m)
{
     vector<int> vec(n + 1, 0);
     return fun(vec, n, m);
}

int main()
{
     int n = 5; // Total number of stairs
     int m = 3; // Maximum number of stairs
     std::cout << "Number of ways to reach the top: " << countWaysToTop(n, m) << std::endl;

     return 0;
}
// itrative 
#include <iostream>
#include <vector>
using namespace std;
int fun(int n, int m)
{
    vector<int> vec(n+1,0);
    vec[1] = 1;
    for(int i=1 ;i<=n ;i++){
        for(int j=1 ; j<=min(i,m) ; j++){
            vec[i] += vec[i-j];
        }
    }
    return vec[n];

}
int main()
{

    cout << fun(5, 3);
    return 0;
}
