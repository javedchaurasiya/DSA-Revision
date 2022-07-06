class Solution
{
public:
    vector<vector<int>> dp;

    bool fun(vector<int> &v, int i, int s)
    {
        if (s == 0)
            return 1;
        if (i < 0 || s < 0)
            return 0;
        if (dp[s][i] != -1)
            return dp[s][i];

        int ans = 1;

        ans = ans & (fun(v, i - 1, s) | fun(v, i - 1, s - v[i]));
        return dp[s][i] = ans;
    }

    bool canPartition(vector<int> &nums)
    {
        int s = accumulate(begin(nums), end(nums), 0);
        if (s & 1)
            return 0;

        s = s / 2;

        dp.resize(s + 1, vector<int>(201, -1));

        return (bool)fun(nums, nums.size() - 1, s);
    }
};