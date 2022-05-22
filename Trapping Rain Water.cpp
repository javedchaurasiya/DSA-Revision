class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        
        if(n<=2)return 0;
        int ans=0;
        vector<int> leftMax(n),rightMax(n);
        int left=v[0],right=v.back();
        for(int i=0;i<n;i++)
        {
            left=max(left,v[i]);
            right=max(right,v[n-i-1]);
            leftMax[i]=left;
            rightMax[n-i-1]=right;
        }
        for(int i=1;i<n-1;i++)
        {
            ans+=min(leftMax[i],rightMax[i])-v[i];
        }
        return ans;
    }
};