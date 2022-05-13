class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int x) {
        
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0,j=v.size()-1;
        while(i<j)
        {
            int sum=v[i].first+v[j].first;
            if(v[i].first+v[j].first==x)return {v[i].second,v[j].second};
            if(sum<x)i++;
            else j--;
        }
        return {};
        
    }
};