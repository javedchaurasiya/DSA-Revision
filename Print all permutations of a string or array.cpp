class Solution {
public:
    
    unordered_map<int,int> vis;
    
    vector<vector<int>> ans;
    vector<int> res;
    
    
    void fun(vector<int>& v,int ind)
    {
        if(ind==v.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i=0;i<v.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                res.push_back(v[i]);
                fun(v,ind+1);
                vis[i]=0;
                res.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        sort(begin(nums),end(nums));
        fun(nums,0);
        
        return ans;
    }
};