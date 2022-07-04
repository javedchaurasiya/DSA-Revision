class trie
{
public:
    bool leaf;
    vector<trie *> c;
    trie()
    {
        c.resize(26, NULL);
        leaf = 0;
    }
    void insert(string &s)
    {
        trie *root = this;
        for (auto it : s)
        {
            int ind = it - 'a';
            if (!root->c[ind])
                root->c[ind] = new trie();
            root = root->c[ind];
        }
        root->leaf = 1;
    }
    bool check(string &s)
    {
        trie *root = this;
        bool ans = true;
        for (int i = 0; s[i]; i++)
        {
            int ind = s[i] - 'a';
            if (!root->c[ind])
                root->c[ind] = new trie();
            root = root->c[ind];
            if (i == s.size() - 1)
                root->leaf = 1;
            ans = ans & root->leaf;
        }
        return ans;
    }
};

string completeString(int n, vector<string> &a)
{
    // Write your code here.
    trie *root = new trie();
    sort(begin(a), end(a), [&](string x, string y)
         { return (x.size() < y.size()) || (x.size() == y.size() && lexicographical_compare(begin(x), end(x), begin(y), end(y))); });
    string ans = "";
    int len = 0;
    for (auto it : a)
    {
        if (root->check(it))
        {
            if (it.size() > len)
            {
                len = it.size();
                ans = it;
            }
        }
    }
    return len ? ans : "None";
}