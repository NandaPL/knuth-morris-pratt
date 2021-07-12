#include <bits/stdc++.h>
using namespace std;
string s, t;
vector<int> p(500123), pattern;
int matching(string t, string s)
{
    int n = t.size(), m = s.size();
    p[0] = 0;
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && s[j] != s[i])
        {
            j = p[j - 1];
        }
        if (s[j] == s[i])
            j++;
        p[i] = j;
    }

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && t[i] != s[j])
            j = p[j - 1];
        if (s[j] == t[i])
            j++;
        if (j == m)
            return i - j + 2;
    }
    return -1;
}
int main()
{
    cin >> t;
    int k;
    cin >> k;
    while (k--)
    {
        cin >> s;
        cout << matching(t, s) << endl;
    }
    return 0;
}