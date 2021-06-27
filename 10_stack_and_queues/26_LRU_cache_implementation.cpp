/*
    link: https://practice.geeksforgeeks.org/problems/lru-cache/1

    sol: https://www.geeksforgeeks.org/lru-cache-implementation/

    list(reference): https://www.geeksforgeeks.org/list-cpp-stl/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using doubly linklist
*/
struct Node {
    int key;
    int value;
    Node* next, * pre;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = pre = NULL;
    }
};

class LRUCache
{
    private:
    static unordered_map<int, Node*> hsmap;
    static int capacity, count;
    static Node* head, * tail;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        unordered_map<int, Node*> temp;
        hsmap = temp;
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        head->pre = NULL;
        tail->next = NULL;
        tail->pre = head;
        count = 0;
    }

    static void addToHead(Node* node)
    {
        node->next = head->next;
        node->next->pre = node;
        node->pre = head;
        head->next = node;
    }

    //Function to delete a node.
    static void deleteNode(Node* node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    //Function to return value corresponding to the key.
    static int get(int key)
    {
        //if element is present in map,
        if (hsmap.count(key) > 0)
        {
            Node* node = hsmap[key];
            int result = node->value;

            deleteNode(node);
            addToHead(node);

            //returning the value.
            return result;
        }
        //else we return -1.
        return -1;
    }

    //Function for storing key-value pair.
    static void set(int key, int value)
    {
        if (hsmap.count(key) > 0)
        {
            Node* node = hsmap[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        }
        else
        {
            Node* node = new Node(key, value);
            hsmap[key] = node;
            if (count < capacity) {
                count++;
                addToHead(node);
            }
            else {
                hsmap.erase(tail->pre->key);
                deleteNode(tail->pre);
                addToHead(node);
            }
        }
    }
};

//initializing static members. (as declared privately)
unordered_map<int, Node*> temp;
int LRUCache::capacity = 0;
Node* LRUCache::head = new Node(0, 0);
Node* LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node*> LRUCache::hsmap = temp;





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using list of stl.
*/

/* We can use stl container list as a double ended queue to store the cache keys, with
the descending time of reference from front to back and a set container to check presence
of a key. But to fetch the address of the key in the list using find(), it takes O(N) time.
This can be optimized by storing a reference  (iterator) to each key in a hash map. */

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    // store keys of cache
    list<int> dq;

    // store references of key in cache
    unordered_map<int, list<int>::iterator> ma;
    int csize; // maximum capacity of cache

    public:
    LRUCache(int);
    void refer(int);
    void display();
};

// Declare the size
LRUCache::LRUCache(int n)
{
    csize = n;
}

// Refers key x with in the LRU cache
void LRUCache::refer(int x)
{
    // not present in cache
    if (ma.find(x) == ma.end()) {
        // cache is full
        if (dq.size() == csize) {
            // delete least recently used element
            int last = dq.back();

            // Pops the last elmeent
            dq.pop_back();

            // Erase the last
            ma.erase(last);
        }
    }

    // present in cache
    else
        dq.erase(ma[x]);

    // update reference
    dq.push_front(x);
    ma[x] = dq.begin();
}

// Function to display contents of cache
void LRUCache::display()
{

    // Iterate in the deque and print
    // all the elements in it
    for (auto it = dq.begin(); it != dq.end();
        it++)
        cout << (*it) << " ";

    cout << endl;
}

// Driver Code
int main()
{
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}
