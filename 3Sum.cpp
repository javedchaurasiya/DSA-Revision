class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        int n=v.size();
        if(n<3)return {};
        
        sort(begin(v),end(v));
        int i=0;
        while(i<=n-3)
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                int s=v[i]+v[j]+v[k];
                if(s==0)
                {
                    ans.push_back({v[i],v[j],v[k]});
                    j++;
                    k--;
                    while(j<k&&v[j]==v[j-1])j++;
                    while(j<k&&v[k]==v[k+1])k--;
                }
                else if(s>0)k--;
                else j++;
            }
            i++;
            while(i<=n-3&&v[i]==v[i-1])i++;
        }
        return ans;
    }
};