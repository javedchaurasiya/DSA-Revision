class Solution {
public:
    
    int fun(int n,int& k)
    {
        int f=1;
        while(n>0&&k>=f)
        {
            f=f*n;
            n--;
        }
        
        int ind=k/f;
        k=k%f;
        return ind;
    }
    
    string getPermutation(int n, int k) {
        
        set<int> s;
        
        for(int i=1;i<=n;i++)s.insert(i);
        
        k--;
        
        string ans="";
        
        for(int i=1;i<=n;i++)
        {
            int ind=fun(n-i,k);
            auto it=begin(s);
            advance(it,ind);
            ans+=to_string(*it);
            s.erase(it);
        }
        
        return ans;
        
    }
};