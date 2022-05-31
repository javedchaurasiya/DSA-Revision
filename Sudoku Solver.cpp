class Solution {
public:
    
    bool isSafe(vector<vector<char>>& v,int r,int c,char ch)
    {
        for(int i=0;i<9;i++)
        {
            if(v[i][c]==ch)return 0;
            if(v[r][i]==ch)return 0;
            if(v[r-r%3+i/3][c-c%3+i%3]==ch)return 0;
        }
        v[r][c]=ch;
        return 1;
    }
    
    bool fun(vector<vector<char>>& v,int ind)
    {
        if(ind==81)return 1;
        
        int r=ind/9,c=ind%9;
        
        if(v[r][c]!='.')return fun(v,ind+1);
        
        for(int i=1;i<=9;i++)
        {
            if(isSafe(v,r,c,'0'+i))
            {
                if(fun(v,ind+1))return 1;
                v[r][c]='.';
            }
        }
        return 0;
    }
    
    
    void solveSudoku(vector<vector<char>>& v) {
        fun(v,0);
    }
};