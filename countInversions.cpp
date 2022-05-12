// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long temp[],long long l,long long m,long long r)
    {
        long long inv_count=0;
        long long k=l;
        long long i=l;
        long long j=m;
        while((i<=m-1) && (j<=r))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++]=arr[j++];
                inv_count=(m-i)+inv_count;
            }
            
        }
        while(i<=m-1)
            {
                temp[k++]=arr[i++];
            }
            while(j<=r)
            {
                temp[k++]=arr[j++];
            }
            for(i=l;i<=r;i++)
            {
                arr[i]=temp[i];
            }
            return inv_count;
        
    }
    long long int _ms(long long arr[],long long temp[],long long l,long long r)
    {
        
        long long m,inv_count=0;
        if(r>l)
        {
            m=(l+(r-l)/2);
            inv_count+=_ms(arr,temp,l,m);
            inv_count+=_ms(arr,temp,m+1,r);
            
            inv_count+=merge(arr,temp,l,m+1,r);
        }
        return inv_count;
    }
    long long int ms(long long arr[],long long n)
    {
        long long temp[n];
        return _ms(arr,temp,0,n-1);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long ans=ms(arr,N);
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends