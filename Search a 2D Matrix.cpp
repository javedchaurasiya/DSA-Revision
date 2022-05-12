class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int r=v.size(),c=v[0].size();
        int l=0,h=r*c-1;
        while(l<=h)
        {
            
            int m=l+(h-l)/2;
            // cout<<m<<endl;
            int x=m/c,y=m%c;
            if(v[x][y]==target)return 1;
            else if(v[x][y]>target)h=m-1;
            else l=m+1;
            // cout<<v[x][y]<<endl;
        }
        return 0;
    }
};