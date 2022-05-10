#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &v, int n)
{
    //  Write your code here.
	bool found=0;
	for(int i=n-1;i>0;i--)
	{
		if(v[i]>v[i-1])
		{
			found=1;
			for(int j=n-1;j>=0;j--)
			{
				if(v[j]>v[i-1])
				{
					swap(v[j],v[i-1]);
					sort(begin(v)+i,end(v));
					break;
				}
			}
			break;
		}
	}
	if(!found)sort(begin(v),end(v));
	return v;
}