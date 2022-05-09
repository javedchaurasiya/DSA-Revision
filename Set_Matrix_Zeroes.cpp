class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        bool rowZero=0,columnZero=0;
        int r=v.size();
        int c=v[0].size();
        
        for(int i=0;i<c;i++)
        {
            if(v[0][i]==0)
            {
                rowZero=1;
                break;
            }
        }
        for(int i=0;i<r;i++)
        {
            if(v[i][0]==0)
            {
                columnZero=1;
                break;
            }
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(v[i][j]==0)
                {
                    v[i][0]=0;
                    v[0][j]=0;
                }
            }
        }
        for(int i=1;i<r;i++)
        {
            if(v[i][0]==0)
            {
                for(int j=1;j<c;j++)v[i][j]=0;
            }
        }
        for(int i=1;i<c;i++)
        {
            if(v[0][i]==0)
            {
                for(int j=1;j<r;j++)
                {
                    v[j][i]=0;
                }
            }
        }
        if(rowZero)for(int i=0;i<c;i++)v[0][i]=0;
        if(columnZero)for(int i=0;i<r;i++)v[i][0]=0;
    }
};