// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    int r,c;
    vector<string> ans;
    string s="";
    vector<vector<bool>> vis;
    
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};
    vector<char> dir={'R','D','L','U'};
    
    void fun(vector<vector<int>>& v,int i,int j)
    {
        if(v[i][j]==0)return;
        if(i==r-1&&j==c-1)
        {
            ans.push_back(s);
            return;
        }
        vis[i][j]=1;
        
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k],y=j+dy[k];
            if(min(x,y)<0||x>=r||y>=c||vis[x][y])continue;
            s.push_back(dir[k]);
            fun(v,x,y);
            s.pop_back();
        }
        vis[i][j]=0;
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        r=c=n;
        vis.resize(n,vector<bool>(n,false));
        
        
        fun(m,0,0);
        
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends