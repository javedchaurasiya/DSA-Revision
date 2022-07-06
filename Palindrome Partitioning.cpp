class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> res;

    bool check(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return 0;
        }
        return 1;
    }

    void fun(string &s, int ind)
    {
        if (ind == s.size())
        {
            ans.push_back(res);
            return;
        }
        string x = "";
        for (int i = ind; s[i]; i++)
        {
            x += s[i];
            if (check(x))
            {
                res.push_back(x);
                fun(s, i + 1);
                res.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s)
    {
        fun(s, 0);
        return ans;
    }
};