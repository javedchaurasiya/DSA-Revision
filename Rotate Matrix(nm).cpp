#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &v, int r, int c)
{
	int sr,sc,i,j;
	sr=i=sc=j=0;
	while(sr<r&&sc<c)
	{
		if(sr+1>=r||sc+1>=c)break;
		int pre=v[i+1][j];
		for(int k=j;k<c;k++)
		{
			int cur=v[i][k];
			v[i][k]=pre;
			pre=cur;
		}
		for(int k=i+1;k<r;k++)
		{
			int cur=v[k][c-1];
			v[k][c-1]=pre;
			pre=cur;
		}
		for(int k=c-2;k>=j;k--)
		{
			int cur=v[r-1][k];
			v[r-1][k]=pre;
			pre=cur;
		}
		for(int k=r-2;k>i;k--)
		{
			int cur=v[k][j];
			v[k][j]=pre;
			pre=cur;
		}
		i++;
		j++;
		sc++;
		sr++;
		r--;
		c--;
	}
}