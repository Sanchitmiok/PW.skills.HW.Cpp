#include<iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int *ptr = (a + k - 1);
    cout << *ptr;
    return 0;
}
 