// suffix trie


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

int main() {
    string input = "hello";
    string suffixes[] = { "lo", "ell", "hello" };

    Trie t;
    for (int i = 0;i < input.size();i++) {
        t.insert(input.substr(i));
    }

    for (auto i : suffixes) {
        if (t.search(i)) {
            cout << "Yes, it is present" << endl;
        }
        else {
            cout << "No, it is not present" << endl;
        }
    }
}