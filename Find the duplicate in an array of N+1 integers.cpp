#include <bits/stdc++.h> 
int findDuplicate(vector<int> &v, int n){
	// Write your code here.
	for(int i=0;i<v.size();i++)
	{
		int ind=abs(v[i]);
		if(v[ind]<0)return ind;
		v[ind]=-v[ind];
	}
	return 0;
}
