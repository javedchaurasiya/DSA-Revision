#include <bits/stdc++.h>
#define ll long long int

ll fun(ll x,ll n,ll m)
{
	if(n==0)return 1;
	ll res=fun((x*x)%m,n/2,m);
	if(n&1)res=(res*x)%m;
	return res;
}

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	return (int)fun((ll)x,(ll)n,(ll)m);
}