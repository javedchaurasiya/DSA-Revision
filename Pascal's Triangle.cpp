#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
	for(int i=0;i<n;i++)
	{
		vector<long long int> v;
		v.push_back(1);
		if(i==0)
		{
			ans.push_back(v);
			continue;
		}
		int x=ans[i-1].size();
		for(int j=0;j<x;j++)
		{
			if(j==x-1)v.push_back(1);
			else
			{
				v.push_back(ans[i-1][j]+ans[i-1][j+1]);
			}
		}
		ans.push_back(v);
	}
	return ans;
}
