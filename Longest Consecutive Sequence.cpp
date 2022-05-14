class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        
        if(v.empty())return 0;
        
        unordered_set<int> s(begin(v),end(v));
        
        int ans=1;
        
        while(!s.empty())
        {
            auto it=begin(s);
            int x=*it;
            int res=1;
            int i=x-1;
            while(1)
            {
                if(!s.count(i))break;
                res++;
                s.erase(i);
                i--;
            }
            i=x+1;
            while(1)
            {
                if(!s.count(i))break;
                res++;
                s.erase(i);
                i++;
            }
            ans=max(ans,res);
            s.erase(x);
        }
        return ans;
    }
};