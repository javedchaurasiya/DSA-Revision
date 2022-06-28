#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &v, int k)
{
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    int r = v.size();
    for (int i = 0; i < r; i++)
        q.push({v[i][0], {i, 0}});

    while (!q.empty())
    {
        auto it = q.top();
        ans.push_back(it.first);
        int row = it.second.first;
        int col = it.second.second;
        q.pop();
        if (col + 1 < v[row].size())
        {
            q.push({v[row][col + 1], {row, col + 1}});
        }
    }
    return ans;
}
