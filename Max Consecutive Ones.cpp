class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int ans=0;
        int n=v.size();
        int x=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==1)x++;
            else
            {
                ans=max(ans,x);
                x=0;
            }
        }
        ans=max(ans,x);
        return ans;
    }
};