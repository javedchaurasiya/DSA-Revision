// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string res = "";
    vector<string> ans;

    void fun(string &s, int ind)
    {
        if (!res.empty())
            ans.push_back(res);
        for (int i = ind; s[i]; i++)
        {
            res += s[i];
            fun(s, i + 1);
            res.pop_back();
        }
        return;
    }
    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        ans.clear();
        res = "";
        //  sort(begin(s),end(s));
        fun(s, 0);
        sort(begin(ans), end(ans));
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends