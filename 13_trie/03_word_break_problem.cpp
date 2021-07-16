/*
    link: https://www.geeksforgeeks.org/word-break-problem-trie-solution/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// A DP and Trie based program to test whether
// a given string can be segmented into
// space separated words in dictionary
#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// returns true if string can be segmented into
// space separated words, otherwise returns false
bool wordBreak(string str, TrieNode* root)
{
    int size = str.size();

    // Base case
    if (size == 0) return true;

    // Try all prefixes of lengths from 1 to size
    for (int i = 1; i <= size; i++)
    {
        // The parameter for search is str.substr(0, i)
        // str.substr(0, i) which is prefix (of input
        // string) of length 'i'. We first check whether
        // current prefix is in dictionary. Then we
        // recursively check for remaining string
        // str.substr(i, size-i) which is suffix of
        // length size-i
        if (search(root, str.substr(0, i)) &&
            wordBreak(str.substr(i, size - i), root))
            return true;
    }

    // If we have tried all prefixes and none
    // of them worked
    return false;
}

// Driver program to test above functions
int main()
{
    string dictionary[] = { "mobile","samsung","sam",
                        "sung","ma\n","mango",
                        "icecream","and","go","i",
                        "like","ice","cream" };
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    struct TrieNode* root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);

    wordBreak("ilikesamsung", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("iiiiiiii", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmango", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmangok", root) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
