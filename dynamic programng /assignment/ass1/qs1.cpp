#include <iostream>
#include <stack>
using namespace std;
int lonegst_substr(string &s, string &t)
{
    int count = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i] == t[j])
            {
                int k = i;
                while (s[k] == t[j] and k<s.size() and j<t.size())
                {
                    count++;
                    k++;
                    j++;
                }
                if (count != 0)
                {
                    st.push(count);
                    count = 0;
                }
            }
        }
    }
    int max = st.top();
    while (!st.empty())
    {
        if(max>=st.top()){
            st.pop();
        }else {
            max = st.top();
            st.pop();
        }
    }
    return max;
}
int main()
{
       string s = "abcdefg001";
    string t = "abcde0002";
    cout<<lonegst_substr(s,t);

    return 0;
}
