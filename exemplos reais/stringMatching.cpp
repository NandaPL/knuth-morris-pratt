// questão https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>
using namespace std;
string s, t;
vector<int> p(1001233), match;
vector<int> matching(string t, string s)
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
            match.push_back(i - j + 1);
    }
    return match;
}
int main()
{
    cin >> t >> s;
    matching(t, s);
    cout << match.size() << endl;
    return 0;
}