// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    vector<int> ans;
    
    void fun(vector<int>& v,int ind,int s)
    {
        ans.push_back(s);
        if(ind>=v.size())return;
        for(int i=ind;i<v.size();i++)
        {
            s+=v[i];
            fun(v,i+1,s);
            s-=v[i];
        }
        return;
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        fun(arr,0,0);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends