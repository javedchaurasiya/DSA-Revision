#define ll long long int
class Solution
{
public:
    ll dp[10001][14];

    ll fun(vector<int> &v, int i, int s)
    {
        if (s == 0)
            return 0;
        if (i < 0 || s < 0)
            return INT_MAX;

        if (dp[s][i] != -1)
            return dp[s][i];

        ll ans = INT_MAX;
        ans = min(ans, min(1 + fun(v, i, s - v[i]), fun(v, i - 1, s)));
        return dp[s][i] = ans;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));
        ll result = fun(coins, coins.size() - 1, amount);
        return result >= INT_MAX ? -1 : result;
    }
};