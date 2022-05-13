#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<ll> v;
        for(auto it:nums)v.push_back(it);
        sort(begin(v),end(v));
        int n=v.size();
        vector<vector<int>> ans;
        int i=0,j;
        while(i<n-3)
        {
            j=i+1;
            while(j<n-2)
            {
                int p=j+1,q=n-1;
                while(p<q)
                {
                    ll s=v[i]+v[j]+v[p]+v[q];
                    if(s==target)
                    {
                        ans.push_back({(int)v[i],(int)v[j],(int)v[p],(int)v[q]});
                        p++;
                        q--;
                        while(p<q&&v[p]==v[p-1])p++;
                        while(p<q&&v[q]==v[q+1])q--;
                    }
                    else if(s>target)q--;
                    else p++;
                }
                j++;
                while(j<n-2&&v[j]==v[j-1])j++;
            }
            i++;
            while(i<n-3&&v[i]==v[i-1])i++;
        }
        return ans;
    }
};