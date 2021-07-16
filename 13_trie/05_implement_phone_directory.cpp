/*
    link: https://practice.geeksforgeeks.org/problems/phone-directory4628/1#

    sol: https://www.geeksforgeeks.org/implement-a-phone-directory/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
class Solution {
    public:
    struct TrieNode {
        unordered_map<char, TrieNode*> child;
        bool isLast;

        TrieNode() {
            for (char i = 'a'; i <= 'z'; i++)
                child[i] = NULL;

            isLast = false;
        }
    };

    TrieNode* root = NULL;

    void insert(string s)
    {
        int len = s.length();

        TrieNode* itr = root;
        for (int i = 0; i < len; i++)
        {
            TrieNode* nextNode = itr->child[s[i]];
            if (nextNode == NULL)
            {
                nextNode = new TrieNode();
                itr->child[s[i]] = nextNode;
            }

            itr = nextNode;

            if (i == len - 1)
                itr->isLast = true;
        }
    }

    void displayContactsUtil(TrieNode* curNode, string prefix, vector<string>& v)
    {
        if (curNode->isLast)
        {
            v.push_back(prefix);
        }

        for (char i = 'a'; i <= 'z'; i++)
        {
            TrieNode* nextNode = curNode->child[i];
            if (nextNode != NULL)
                displayContactsUtil(nextNode, prefix + (char)i, v);
        }
    }


    vector<vector<string>> displayContactsHelp(string str)
    {
        vector<vector<string>> ans;

        TrieNode* prevNode = root;

        string prefix = "";
        int len = str.size();

        int i;
        for (i = 0; i < len; i++)
        {
            prefix += (char)str[i];

            char lastChar = prefix[i];

            TrieNode* curNode = prevNode->child[lastChar];

            if (curNode == NULL) break;

            vector<string> v;

            displayContactsUtil(curNode, prefix, v);
            ans.push_back(v);

            prevNode = curNode;
        }

        for (; i < len; i++)
        {
            ans.push_back({ "0" });
        }

        return ans;
    }

    void insertIntoTrie(string contacts[], int n)
    {
        root = new TrieNode();

        for (int i = 0; i < n; i++)
            insert(contacts[i]);
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        insertIntoTrie(contact, n);

        return displayContactsHelp(s);
    }
};