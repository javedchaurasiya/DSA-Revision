// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
#define ll long long int
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.

    int dp[203][203];

    int fun(int f, int n)
    {
        if (f <= 1)
            return f;
        if (n <= 1)
            return f;

        if (dp[f][n] != -1)
            return dp[f][n];

        int ans = 10000;

        for (int i = 1; i <= f; i++)
        {
            ans = min(ans, 1 + max(fun(i - 1, n - 1), fun(f - i, n)));
        }
        return dp[f][n] = ans;
    }

    int eggDrop(int n, int k)
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        return fun(k, n);
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends