#include <iostream>
using namespace std;

long long countBinaryNumbers(int n) {
    long long endWithZero = 1;
    long long endWithOne = 1;

    for (int i = 2; i <= n; i++) {
        long long temp = endWithZero;
        endWithZero = endWithZero + endWithOne;
        endWithOne = temp;
    }

    return endWithZero + endWithOne;
}

int main() {
    int n = 5;
    long long result = countBinaryNumbers(n);

    cout << "The number of " << n << "-digit binary numbers without consecutive 1's is: " << result << endl;

    return 0;
}


//My code ' recursive
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int fun(vector<int> &vec, int n)
{
    // base case;

    if (n == 0 or n == 1 )
        return 1;
    if(n==2) return 2;
    int count = 1;
    int value = 10;
    for (int i = 0; i < n; i++)
    {
        value = pow(10, i);
        count++;
        if (value == 1 or value == 10)
        {
            continue;
        }
        string str = to_string(value);

        for (int j = 1; j < str.size(); j++)
        {
            char pre = str[j - 1];

            if (pre != '1')
            {
                int size = str.size() - j - 1;
                if (vec[size] != 0)
                    count += vec[size];
                else
                {
                    count += fun(vec, size);
                }
            }
        }
    }

    return vec[n] = count;
}

int count(int n)
{
    vector<int> vec(n + 1, 0);

    return fun(vec, n);
}
int main()
{

    cout << count(3) << endl;
    return 0;
}
// itrative
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int countBinaryNumbers(int n) {
    // Base cases: n = 0, n = 1, and n = 2
    if (n == 0 || n == 1)
        return 1;
    if (n == 2)
        return 2;

    vector<int> dp(n + 1, 0);

    dp[0] = 1; // 0-digit binary number (empty string) is a valid number.
    dp[1] = 2; // 1-digit binary numbers: 0 and 1

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 5;
    int result = countBinaryNumbers(n);

    cout << "The number of " << n << "-digit binary numbers without consecutive 1's is: " << result << endl;

    return 0;
}

