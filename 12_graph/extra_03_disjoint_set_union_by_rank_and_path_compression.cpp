/*
    what is disjoint set ?
    what is union by rank ?
    what is path compression ?
    https://www.geeksforgeeks.org/disjoint-set-data-structures/
    https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/

    Partitioning the individuals into different sets according to the groups
    in which they fall. This method is known as disjoint set data structure which
    maintains collection of disjoint sets and each set is represented by its
    representative which is one of its members.

    video: https://youtu.be/3gbO7FDYNFQ?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(4 * alpha) => approx. O(4) constant time
*/

int parent[1e5];
int rank[1e5];

static int N;

void makeSet() {
    for (int i = 0;i < N;i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPar(int node) {
    if (node == parent[node]) return node;

    // here it's path compression
    return parent[node] = findPar(parent[node]);
}

// union by rank
void union(int u, int v) {
    u = findPar(u);
    v = findPar(v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}


int main() {
    cin >> N;

    makeSet();

    // if given M operation
    int M;
    cin >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        union(u, v);
    }

    // if we want to check 2 and 3 belong to same component or not
    if (findPar(2) == findPar(3)) cout << "same component" << endl;
    else cout << "different component" << endl;

}