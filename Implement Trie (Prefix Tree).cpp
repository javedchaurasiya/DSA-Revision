class Trie
{
public:
    bool leaf;
    vector<Trie *> child;
    Trie()
    {
        child.resize(26);
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        leaf = false;
    }

    void insert(string word)
    {
        Trie *root = this;
        for (auto it : word)
        {
            int ind = it - 'a';
            if (!root->child[ind])
                root->child[ind] = new Trie();
            root = root->child[ind];
        }
        root->leaf = 1;
    }

    bool search(string word)
    {
        Trie *root = this;
        for (auto it : word)
        {
            int ind = it - 'a';
            if (!root->child[ind])
                return 0;
            root = root->child[ind];
        }
        return root->leaf;
    }

    bool startsWith(string prefix)
    {
        Trie *root = this;
        for (auto it : prefix)
        {
            int ind = it - 'a';
            if (!root->child[ind])
                return 0;
            root = root->child[ind];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */