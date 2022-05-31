#include<bits/stdc++.h>

unordered_map<string,int> m;
vector<vector<string>> ans;
vector<string> res;

void fun(string& s,int ind)
{
    if(ind==s.size())
    {
        ans.push_back(res);
        return;
    }
    
    string x="";
    for(int i=ind;i<s.size();i++)
    {
        x.push_back(s[i]);
        if(m.count(x))
        {
            res.push_back(x);
            fun(s,i+1);
            res.pop_back();
        }
    }
    return;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    m.clear();
    ans.clear();
    res.clear();
    for(auto it:dictionary)m[it]=1;
    fun(s,0);
    vector<string> result;
    
    for(auto it:ans)
    {
        string x="";
        for(auto jt:it)x+=jt+" ";
        x.pop_back();
        if(x!="")result.push_back(x);
    }
    return result;
}