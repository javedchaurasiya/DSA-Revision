#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &v)
{
    // Write your code here.
	sort(begin(v),end(v));
	vector<vector<int>> ans;
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		int s=v[i][0],e=v[i][1];
		int j=i;
		while(j<n)
		{
			if(e<v[j][0])break;
			e=max(e,v[j][1]);
			j++;
		}
		ans.push_back({v[i][0],e});
		i=j-1;
	}
	return ans;
}
