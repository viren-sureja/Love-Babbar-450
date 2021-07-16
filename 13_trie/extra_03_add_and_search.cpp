/*
    link: https://youtu.be/h-F2jRUzpBo?list=PLEJXowNB4kPyi859E6qGUs7jlpQehJndl

    here "." means we can put any character there
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O( N + 26^N )
*/
class WordDictionary {
    struct node {
        char c;
        int end;
        node* child[26];
    };
    node* getNode(char c)
    {
        node* newnode = new node;
        newnode->c = c;
        newnode->end = 0;
        for (int i = 0;i < 26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
    node* root = getNode('/');

    void Trie_insert(string s)
    {
        int index;
        int i = 0;
        node* curr = root;
        while (s[i])
        {
            index = s[i] - 'a';
            if (!curr->child[index])
                curr->child[index] = getNode(s[i]);
            curr = curr->child[index];
            ++i;
        }
        curr->end += 1;
    }

    bool Trie_search(string s, node* curr, int pos, int n)
    {
        if (s[pos] == '.')
        {
            bool res = false;
            node* current = curr;
            for (int i = 0;i < 26;++i)
            {
                if (pos == n - 1 && curr->child[i])
                {
                    current = curr->child[i];
                    res |= current->end > 0 ? true : false;
                }
                else if (curr->child[i] && Trie_search(s, curr->child[i], pos + 1, n))
                    return true;
            }
            return res;
        }
        else if (curr->child[s[pos] - 'a'])
        {
            if (pos == n - 1)
            {
                curr = curr->child[s[pos] - 'a'];
                return curr->end > 0 ? true : false;
            }
            return Trie_search(s, curr->child[s[pos] - 'a'], pos + 1, n);
        }
        return false;
    }
    public:
        /** Initialize your data structure here. */
    WordDictionary() {
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie_insert(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return Trie_search(word, root, 0, word.size());
    }
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */