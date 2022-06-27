#include <bits/stdc++.h>

bool check(vector<int> &v, int b, int x)
{
    int ct = 1;
    int s = 0;
    if (b > v.size())
        return 0;
    for (auto it : v)
    {
        if (it > x)
            return 0;
        if (s + it <= x)
            s += it;
        else
        {
            s = it;
            ct++;
        }
    }
    return ct <= b;
}

int Solution::books(vector<int> &v, int b)
{
    int l = *min_element(begin(v), end(v)), h = accumulate(begin(v), end(v), 0);
    int ans = -1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (check(v, b, m))
        {
            ans = m;
            h = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;