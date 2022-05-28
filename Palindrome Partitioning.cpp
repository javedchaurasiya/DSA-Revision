class Solution {
public:
    
    vector<vector<string>> ans;
    vector<string> res;
    
    bool isPal(string& s,int i,int j)
    {
        while(i<j)if(s[i++]!=s[j--])return 0;
        return 1;
    }
    
    void fun(string& s,int ind)
    {
        if(ind>=s.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i=ind;s[i];i++)
        {
            if(isPal(s,ind,i))
            {
                res.push_back(s.substr(ind,i-ind+1));
                fun(s,i+1);
                res.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        
        fun(s,0);
        
        return ans;
        
    }
};