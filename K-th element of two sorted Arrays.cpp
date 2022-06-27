// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int kthElement(int a[], int b[], int n, int m, int k)
    {
        if (n > m)
            return kthElement(b, a, m, n, k);
        int l = max(0, k - m), h = min(k, n);
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int left = k - mid;
            int ax = mid == 0 ? INT_MIN : a[mid - 1], ay = mid == n ? INT_MAX : a[mid];
            int bx = left == 0 ? INT_MIN : b[left - 1], by = left == m ? INT_MAX : b[left];
            if (ax <= by && bx <= ay)
                return max(ax, bx);
            if (ax > by)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    }
    return 0;
} // } Driver Code Ends