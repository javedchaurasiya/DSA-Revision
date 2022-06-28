class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        unordered_map<int, int> m;
        for (auto it : nums)
            m[it]++;

        for (auto it : m)
        {
            q.push({it.second, it.first});
            if (q.size() > k)
                q.pop();
        }
        vector<int> ans;
        while (!q.empty())
        {
            auto it = q.top();
            ans.push_back(it.second);
            q.pop();
        }
        return ans;
    }
};