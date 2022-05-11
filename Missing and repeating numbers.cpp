#include <bits/stdc++.h> 
#define ll long long int

pair<int,int> missingAndRepeating(vector<int> &v, int x)
{
	
	ll ss,ass,s,as;
	ass=ss=s=as=0;
	ll n=x;
	ass=(n*(n+1)*(2*n+1))/6;
	as=(n*(n+1))/2;
	for(auto it:v)
	{
		s+=(ll)it;
		ss+=(ll)it*(ll)it;
	}
	ll miss=((ass-ss)/(as-s)+(as-s))/2;
	ll rep=miss-as+s;
	return {(int)miss,(int)rep};
}
