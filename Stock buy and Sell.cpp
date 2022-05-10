#include <bits/stdc++.h> 
int maximumProfit(vector<int> &v){
    // Write your code here.
	int maxProfit=0;
	int minCost=INT_MAX;
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		minCost=min(v[i],minCost);
		maxProfit=max(maxProfit,v[i]-minCost);
	}
	return maxProfit;
}