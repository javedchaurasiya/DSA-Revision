// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&v, int n)
    {   
        // Your code here
        unordered_map<int,int> m;
        m[0]=-1;
        int ans=0;
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=v[i];
            if(m.count(s))
            {
                ans=max(ans,i-m[s]);
            }
            else m[s]=i;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends