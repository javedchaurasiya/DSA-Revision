#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
	pair<int,int> p={0,0};
	for(int i=0;i<n;i++)
	{
		if(p.second==0)p={arr[i],1};
		else
		{
			if(p.first==arr[i])p.second++;
			else p.second--;
		}
	}
	int ct=0;
	for(int i=0;i<n;i++)if(p.first==arr[i])ct++;
	if(ct>n/2)return p.first;
	return -1;
}