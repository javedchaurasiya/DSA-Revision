class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> res;
    
    unordered_map<int,int> vis;
    
    void fun(vector<int>& v,int s,int target,int ind)
    {
        if(s==target)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=ind;i<v.size();i++)
        {
            if(s+v[i]<=target)
            {
                if(i>0&&v[i]==v[i-1]&&vis[i-1]==0)continue;
                s+=v[i];
                vis[i]=1;
                res.push_back(v[i]);
                fun(v,s,target,i+1);
                res.pop_back();
                vis[i]=0;
                s-=v[i];
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        
        sort(begin(v),end(v));
        
        fun(v,0,target,0);
        
        return ans;
    }
};