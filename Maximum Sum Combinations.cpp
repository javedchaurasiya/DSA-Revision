vector<int> Solution::solve(vector<int> &a, vector<int> &b, int k)
{

    priority_queue<pair<int, pair<int, int>>> q;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    int n = a.size();
    map<pair<int, int>, int> m;

    q.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
    m[{n - 1, n - 1}] = 1;
    vector<int> ans;
    while (!q.empty())
    {
        if (ans.size() == k)
            break;
        auto it = q.top();
        q.pop();
        ans.push_back(it.first);

        int i = it.second.first;
        int j = it.second.second;

        if (!m.count({i - 1, j}))
        {
            m[{i - 1, j}] = 1;
            q.push({a[i - 1] + b[j], {i - 1, j}});
        }
        if (!m.count({i, j - 1}))
        {
            m[{i, j - 1}] = 1;
            q.push({a[i] + b[j - 1], {i, j - 1}});
        }
    }
    return ans;
}
