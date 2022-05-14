#include <bits/stdc++.h> 
int subarraysXor(vector<int> &v, int x)
{
    //    Write your code here.
	unordered_map<int,int> m;
	m[0]=1;
	int s=0;
	int ans=0;
	for(auto it:v)
	{
		s^=it;
		ans+=m[s^x];
		m[s]++;
	}
	return ans;
}