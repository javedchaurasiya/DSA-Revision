class Solution
{
public:
    int search(vector<int> &v, int x)
    {
        int n = v.size();
        int l = 0, h = n - 1;
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (v[m] == x)
                return m;
            if ((v[m] < v[h] && (x > v[m] && x <= v[h])) || (v[m] > v[h] && (x > v[m] || x <= v[h])))
                l = m + 1;
            else
                h = m - 1;
        }
        return -1;
    }
};