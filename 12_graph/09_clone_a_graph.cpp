/*
    link: https://leetcode.com/problems/clone-graph/

    video: https://youtu.be/jWf5F_shzho
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using DFS
*/
void dfs(Node* node, Node* prev, vector<Node*>& vis) {
    // record in vis array
    vis[prev->val] = prev;

    for (auto curr : node->neighbors) {
        // if not visited
        if (vis[curr->val] == NULL) {
            // make new node
            Node* newNode = new Node(curr->val);

            // save in neighbour of prev
            (prev->neighbors).push_back(newNode);

            // do dfs in both 
            dfs(curr, newNode, vis);
        }
        else {
            // visited then push the address of visited in prev's neighbors
            (prev->neighbors).push_back(vis[curr->val]);
        }
    }
}

Node* cloneGraph(Node* node) {
    if (!node) return NULL;

    vector<Node*> vis(1000, NULL);
    Node* newNode = new Node(node->val);

    dfs(node, newNode, vis);

    return newNode;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using map
*/
unordered_map<Node*, Node*> mp;

Node* cloneGraph(Node* node) {
    if (node && !mp[node]) {
        mp[node] = new Node(node->val);
        for (auto i : node->neighbors) {
            mp[node]->neighbors.push_back(cloneGraph(i));
        }
    }
    return mp[node];
}