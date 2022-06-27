#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define pb push_back
using namespace std;

bool check(vector<ll> &v, ll x, ll c)
{
    ll last = INT_MIN;
    for (ll i : v)
    {
        if (c == 0)
            break;
        if (i - last >= x)
        {
            last = i;
            c--;
        }
    }
    return c == 0;
}

int main()
{
    ll tt;
    cin >> tt;
    while (tt--)
    {
        ll n, c;
        cin >> n >> c;
        vector<ll> v(n);
        for (auto &it : v)
            cin >> it;
        sort(all(v));
        ll l = 0, h = v.back();
        ll ans = -1;
        while (l <= h)
        {
            ll m = (l + h) / 2;
            bool f = check(v, m, c);
            if (f)
            {
                ans = m;
                l = m + 1;
            }
            else
                h = m - 1;
        }
        cout << ans << endl;
    }
}