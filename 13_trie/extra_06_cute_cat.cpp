// does given words exist or is substring in docuement 

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;

    Node(char d) {
        data = d;
        isTerminal = false;
    }
};

class Trie {
    public:
    Node* root;
    Trie() {
        root = new Node('\0');
    }

    void insert(string word) {
        Node* temp = root;

        for (char ch : word) {
            if (temp->m.count(ch) == 0) {
                temp->m[ch] = new Node(ch);
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word) {
        Node* temp = root;

        for (char ch : word) {
            if (temp->m.count(ch) == 0) return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
};

void searchHelper(Trie t, string document, int i, unordered_map<string, bool>& isPresent) {
    Node* temp = t.root;

    for (int j = i; j < document.length(); j++) {
        char ch = document[j];
        if (temp->m.count(ch) == 0) return;

        temp = temp->m[ch];
        if (temp->isTerminal) {
            string out = document.substr(i, j - i + 1);
            isPresent[out] = true;
        }
    }
    return;
}

void documentSearch(string document, string words) {

    // 1. create trie by inserting words
    Trie t;
    for (auto w : words) {
        t.insert(w);
    }

    // 2. searching (Helper fun.)
    unordered_map<string, bool> isPresent;
    for (int i = 0; i < document.length(); i++) {
        searchHelper(t, document, i, isPresent);
    }

    // 3. check which are present or and which not
    for (auto w : words) {
        if (isPresent.count(w) == 0) cout << "False" << endl;
        else cout << "True" << endl;
    }
}

int main() {
    string document = "little cute cat loves to code in c++, java & python";
    string words[5] = { "cute cat", "ttle", "cat", "quick", "big" };

    documentSearch(document, words);

}