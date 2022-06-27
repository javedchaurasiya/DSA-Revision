class Solution
{
public:
    int singleNonDuplicate(vector<int> &v)
    {
        int n = v.size();
        int l = 0, h = n - 1;
        while (l <= h)
        {
            int m = (l + h) / 2;
            int left = m == 0 ? INT_MIN : v[m - 1];
            int right = m == n - 1 ? INT_MAX : v[m + 1];
            if (v[m] != left && v[m] != right)
                return v[m];
            else if ((m & 1 && v[m] == left) || (!(m & 1) && v[m] == right))
                l = m + 1;
            else
                h = m - 1;
        }
        return -1;
    }
};