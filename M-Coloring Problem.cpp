// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool check(vector<int> l[],int v,int c,vector<int> color)
{
    for(auto x : l[v])
    {
        if(color[x]==c)return false;
    }
    return true;
}
bool fun(vector<int> l[],int a,int n,int m,vector<int> &c)
{
    if(a==n)return true;
    for(int i=1;i<=m;i++)
    {
        if(check(l,a,i,c))
        {
            c[a]=i;
            if(fun(l,a+1,n,m,c))return true;
        }
        c[a]=0;
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code herevector>
    vector<int> l[101];
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            if(graph[i][j])
            {
                l[i].push_back(j);
                
            }
        }
    }
    vector<int> color(n,0);
    return fun(l,0,n,m,color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends