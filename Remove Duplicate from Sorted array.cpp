class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        
        int n=v.size(),i=1,j=1;
        if(n<=1)return n;
        
        while(j<n)
        {
            if(v[i-1]==v[j])j++;
            else v[i++]=v[j++];
        }
        return i;
    }
};