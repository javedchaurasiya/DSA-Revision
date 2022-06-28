class Solution
{
public:
    int findPivot(vector<int> &v, int ind, int l, int h)
    {
        int i, j;
        i = j = l;
        swap(v[ind], v[h]);
        while (j <= h)
        {
            if (v[j] < v[h])
                swap(v[i++], v[j]);
            j++;
        }
        swap(v[i], v[h]);
        return i;
    }

    int findKthLargest(vector<int> &v, int k)
    {
        int n = v.size();
        int l = 0, h = n - 1;
        k = n - k;
        while (l <= h)
        {
            int ind = l + rand() % (h - l + 1);
            int pivot = findPivot(v, ind, l, h);
            if (pivot == k)
                return v[k];
            else if (pivot > k)
                h = pivot - 1;
            else
                l = pivot + 1;
        }
        return -1;
    }
};

// 1,2,3,4,5,6