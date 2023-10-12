#include <iostream>
#include <vector>
using namespace std;
// Itrative bottom to top
int fun(int n)
{
    vector<int> v(n + 1, 0);
    v[0] = 0;
    v[1] = 1;
    v[2] = 1;
    if (n == 0)
        return v[0];
    if (n == 1)
        return v[1];
    if (n == 2)
        return v[2];
    int total = 0;
    for (int i = 3; i <= n; i++)
    {
        total = 0;
        total += v[i - 1] + v[i - 2] + v[i - 3];
        v[i] = total;
    }
    return v[n];
}
// recursive aproach
int fun3(vector<int> &v, int n)
{
    if (n == 0)
        return v[0];
    if (n == 1)
        return v[1];
    if (n == 2)
        return v[2];
    if (v[n] != 0)
        return v[n];

    return v[n] = fun3(v, n - 1) + fun3(v, n - 2) + fun3(v, n - 3);
}

int fun2(int n)
{
    vector<int> vec(n + 1, 0);
    vec[0] = 0;
    vec[1] = 1;
    vec[2] = 1;
    return fun3(vec, n);
}
int main()
{
    cout << fun2(7); // expected 13

    return 0;
}
