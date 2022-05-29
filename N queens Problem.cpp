class Solution {
public:
    
    int maxSize=30;
    
    unordered_map<int,int> colMap;
    unordered_map<int,int> leftDiagMap;
    unordered_map<int,int> rightDiagMap;
    
    vector<vector<string>> ans;
    vector<string> res;
    
    
    void fun(int row,int n)
    {
        if(row==n)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(colMap[i]||leftDiagMap[row-i]||rightDiagMap[row+i])continue;
            
            colMap[i]=1;
            leftDiagMap[row-i]=1;
            rightDiagMap[row+i]=1;
            
            string s=string(n,'.');
            s[i]='Q';
            
            res.push_back(s);
            fun(row+1,n);
            res.pop_back();
            
            colMap[i]=0;
            leftDiagMap[row-i]=0;
            rightDiagMap[row+i]=0;
            
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        fun(0,n);
        
        return ans;
    }
};