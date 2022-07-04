class Trie
{

public:
    int count;
    int end;
    vector<Trie *> child;
    Trie()
    {
        // Write your code here.
        child.resize(26, NULL);
        count = 0;
        end = 0;
    }

    void insert(string &word)
    {
        // Write your code here.
        Trie *root = this;
        for (auto it : word)
        {
            int ind = it - 'a';
            if (!root->child[ind])
                root->child[ind] = new Trie();
            root = root->child[ind];
            root->count++;
        }
        root->end++;
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Trie *root = this;
        for (auto it : word)
        {
            int ind = it - 'a';
            if (!root->child[ind])
                return 0;
            root = root->child[ind];
        }
        return root->end;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Trie *root = this;
        for (auto it : word)
        {
            int ind = it - 'a';
            if (!root->child[ind])
                return 0;
            root = root->child[ind];
        }
        return root->count;
    }

    void erase(string &word)
    {
        // Write your code here.
        Trie *root = this;
        for (auto it : word)
        {
            int ind = it - 'a';
            root = root->child[ind];
            root->count--;
        }
        root->end--;
    }
};
