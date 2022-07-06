class Solution
{
public:
    unordered_map<string, int> m;

    int dp[301][301];

    int fun(string &s, int i, int j)
    {
        if (i > j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        string x = "";
        dp[i][j] = 0;
        for (int k = i; k <= j; k++)
        {
            x += s[k];

            if (m.count(x))
            {
                if (fun(s, k + 1, j))
                    return dp[i][j] = 1;
            }
        }
        return dp[i][j];
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        memset(*dp, -1, sizeof(dp));

        m.clear();

        for (auto &it : wordDict)
            m[it] = 1;

        return fun(s, 0, s.size() - 1);
    }
};