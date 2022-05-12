#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &v)
{
    // Write your code here.
	int n=v.size();
	vector<pair<int,int>> a(2,{0,0});
	for(auto it:v)
	{
		bool found=0;
		for(int i=0;i<2;i++)
		{
			if(a[i].first==it)
			{
				found=1;;
				a[i].second++;
				break;
			}
		}
		if(!found)
		{
			bool zero=0;
			for(int i=0;i<2;i++)
			{
				if(a[i].second==0)
				{
					a[i]={it,1};
					zero=1;
					break;
				}
			}
			if(!zero)for(int i=0;i<2;i++)a[i].second--;
		}
	}
	int x=0,y=0;
	for(auto it:v)
	{
		if(it==a[0].first)x++;
		else if(it==a[1].first)y++;
	}
	vector<int> ans;
	if(x>n/3)ans.push_back(a[0].first);
	if(y>n/3)ans.push_back(a[1].first);
	return ans;
}