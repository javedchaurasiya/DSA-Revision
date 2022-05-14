class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // return 0;
        int ans=0;
        int n=s.size(),i=0,j=0;
        unordered_map<char,int> v;
        while(j<n)
        {
            int ind=s[j]-'a';
            v[ind]++;
            if(v[ind]>1)
            {
                while(i<j&&v[ind]>1)
                {
                    v[s[i++]-'a']--;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};