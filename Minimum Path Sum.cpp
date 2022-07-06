#define ll long long int
class Solution
{
public:
    int dp[201][201];

    int fun(vector<vector<int>> &v, int i, int j)
    {
        int r = v.size(), c = v[0].size();
        if (i == r - 1 && j == c - 1)
            return v[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        if (i + 1 < r)
            ans = min(ans, v[i][j] + fun(v, i + 1, j));
        if (j + 1 < c)
            ans = min(ans, v[i][j] + fun(v, i, j + 1));
        return dp[i][j] = ans;
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        return fun(grid, 0, 0);
    }
};