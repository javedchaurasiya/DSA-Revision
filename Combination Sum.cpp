class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    
    
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
                s+=v[i];
                res.push_back(v[i]);
                fun(v,s,target,i);
                res.pop_back();
                s-=v[i];
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        sort(begin(v),end(v));
        
        fun(v,0,target,0);
        return ans;
    }
};