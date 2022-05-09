#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long ans=LLONG_MIN;
	long long s=0;
	for(int i=0;i<n;i++)
	{
		s+=arr[i];
		if(s<0)s=0;
		ans=max(ans,s);
	}
	return ans;
}