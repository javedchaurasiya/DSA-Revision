#define ll long long int

class Solution {
public:
    
    int merge(vector<int>& v,vector<int>& t,int l,int m,int h)
    {
        int ans=0;
        int i=l,j=m+1;
        for(i=l;i<=m;i++)
        {
            while(j<=h && (ll)v[i]>2ll*(ll)v[j])j++;
            ans+=j-(m+1);
        }
        int k=l;
        i=l,j=m+1;
        while(i<=m&&j<=h)
        {
            if(v[i]<v[j])t[k++]=v[i++];
            else t[k++]=v[j++];
        }
        
        while(i<=m)t[k++]=v[i++];
        while(j<=h)t[k++]=v[j++];
        for(i=l;i<=h;i++)v[i]=t[i];
        return ans;
    }
    
    int divideAndMerge(vector<int>& v,vector<int>& t,int l,int h)
    {
        if(l>=h)return 0;
        int m=(l+h)/2;
        int ans=divideAndMerge(v,t,l,m);
        ans+=divideAndMerge(v,t,m+1,h);
        ans+=merge(v,t,l,m,h);
        return ans;
    }
    
    int reversePairs(vector<int>& v) {
        vector<int> t(v.size());
        return divideAndMerge(v,t,0,v.size()-1);
    }
};