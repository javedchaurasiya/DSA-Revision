class Solution {
public:
    unordered_map<int,int> m;
    vector<vector<int>> ans;
    
    void fun(vector<int>& v,int ind,vector<int>& a)
    {
        ans.push_back(a);
        if(ind>=v.size())return;
        for(int i=ind;i<v.size();i++)
        {
            if(i>0&&v[i]==v[i-1]&&m[i-1]==0)continue;
            m[i]=1;
            a.push_back(v[i]);
            fun(v,i+1,a);
            a.pop_back();
            m[i]=0;
        }
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> a;
        sort(begin(nums),end(nums));
        fun(nums,0,a);
        return ans;
    }
};