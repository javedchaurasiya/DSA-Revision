class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size();
        if (n > m)
            return findMedianSortedArrays(b, a);
        int s = n + m;
        int k = (s + 1) / 2;

        int l = max(0, k - m), h = min(k, n);
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int left = k - mid;
            int ax = mid == 0 ? INT_MIN : a[mid - 1], ay = mid == n ? INT_MAX : a[mid];
            int bx = left == 0 ? INT_MIN : b[left - 1], by = left == m ? INT_MAX : b[left];
            if (ax <= by && bx <= ay)
            {
                if (s & 1)
                    return (double)max(ax, bx);
                return ((double)max(ax, bx) + (double)min(ay, by)) / (double)2;
            }
            else if (ax > by)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return 0.0;
    }
};