#include<bits/stdc++.h>
double maximumValue (vector<pair<int, int>>& v, int n, int weight)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    double ans=0.0;
    
    sort(begin(v),end(v),[&](pair<int,int>& a,pair<int,int>& b){
       return (double)a.second/(double)a.first>(double)b.second/(double)b.first; 
    });
    
    for(auto it:v)
    {
        if(weight==0)break;
        if(weight>=it.first)
        {
            weight-=it.first;
            ans+=(double)it.second;
        }
        else
        {
            ans+=((double)it.second*(double)weight)/(double)it.first;
            weight=0;
        }
    }
    return ans;
}