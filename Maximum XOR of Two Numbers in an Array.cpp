class Solution
{
public:
    class trie
    {
    public:
        int key = 0;
        trie *child[2];
        trie()
        {
            key = 0;
            child[0] = child[1] = NULL;
        }
        void insert(int x)
        {
            trie *root = this;
            for (int i = 31; i >= 0; i--)
            {
                bool ind = (1 << i) & x;
                if (!root->child[ind])
                    root->child[ind] = new trie();
                root = root->child[ind];
            }
            root->key = x;
        }
        int find(int x)
        {
            trie *root = this;
            for (int i = 31; i >= 0; i--)
            {
                bool ind = (1 << i) & x;
                if (root->child[1 - ind])
                    root = root->child[1 - ind];
                else
                    root = root->child[ind];
            }
            return x ^ root->key;
        }
    };
    int findMaximumXOR(vector<int> &v)
    {
        trie *root = new trie();
        for (auto it : v)
            root->insert(it);
        int ans = 0;
        for (auto it : v)
            ans = max(ans, root->find(it));
        return ans;
    }
};