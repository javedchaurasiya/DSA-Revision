class Solution
{
public:
    int dp[105][105];
    vector<int> a;

    int fun(vector<int> &v, int i, int j)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int len = *upper_bound(begin(a), end(a), v[j]);
        int ind = (lower_bound(begin(a), end(a), v[i]) - begin(a)) - 1;
        len = len - a[ind];

        int ans = INT_MAX;
        for (int k = i; k <= j; k++)
        {
            ans = min(ans, len + fun(v, i, k - 1) + fun(v, k + 1, j));
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        sort(begin(v), end(v));
        a = v;
        a.push_back(n);
        a.push_back(0);
        sort(begin(a), end(a));

        return fun(v, 0, v.size() - 1);
    }
};