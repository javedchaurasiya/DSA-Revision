// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
#define ll long long int	
	
	int check(ll x,ll n,ll m)
	{
	    ll ans=1;
	    for(int i=0;i<n;i++)
	    {
	        
	        ans=ans*x;
	        if(ans>m)return 1;
	    }
	    return ans==m?0:-1;
	}
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int l=1,h=m;
	    while(l<=h)
	    {
	        int mid=l+(h-l)/2;
	       // cout<<mid<<endl;
	        int x=check((ll)mid,(ll)n,(ll)m);
	        if(x==0)return mid;
	        else if(x==1)h=mid-1;
	        else l=mid+1;
	    }
	    return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends