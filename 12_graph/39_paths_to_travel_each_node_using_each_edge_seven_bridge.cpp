/*
    link (just refer): https://www.geeksforgeeks.org/paths-travel-nodes-using-edgeseven-bridges-konigsberg/

    video: https://youtu.be/WY6Jsp3NxIk
*/



// ----------------------------------------------------------------------------------------------------------------------- //
//TIME COMPLEXITY: O(V+E)
#include<bits/stdc++.h>
using namespace std;
#define V 5
#define pb push_back

unordered_map<int, vector<int>> adj;

void DFS(int curr, vector<bool>& visited)
{
    visited[curr] = true;
    for (auto it : adj[curr])
    {
        if (!visited[it])
            DFS(it, visited);
    }
}

bool Connected_Graph()
{
    vector<bool> visited(V + 1, false);
    int node = -1;	//Node to start DFS
    for (int i = 0;i < V;++i)
        if (adj[i].size() > 0)
        {
            node = i;	//Found a node to start DFS
            break;
        }
    if (node == -1)	//No start node was found-->No edges are present in graph
        return true; //It's always Eulerian

    DFS(node, visited);
    //Check if all the non-zero vertices are visited
    for (int i = 0;i < V;++i)
        if (visited[i] == false and adj[i].size() > 0)
            return false;	//We have edges in multi-component
    return true;
}

int find_Euler()
{
    if (!Connected_Graph())	//multi-component edged graph
        return 0;		//All non-zero degree vertices should be connected

    //Count odd-degree vertices
    int odd = 0;
    for (int i = 0;i < V;++i)
        if (adj[i].size() & 1)
            odd += 1;

    if (odd > 2)	//Only start and end node can have odd degree
        return 0;

    return (odd == 0) ? 2 : 1;	//1->Semi-Eulerian...2->Eulerian
}

void findEuler_Path_Cycle()
{
    int ret = find_Euler();
    if (ret == 0)
        cout << "Graph is NOT a Euler graph\n";
    else if (ret == 1)
        cout << "Graph is Semi-Eulerian\n";
    else
        cout << "Graph is Eulerian (Euler circuit)\n";
}

int main()
{
    adj[0].pb(1);
    adj[1].pb(0);
    adj[0].pb(2);
    adj[2].pb(0);
    adj[2].pb(1);
    adj[1].pb(2);
    adj[0].pb(3);
    adj[3].pb(0);
    adj[3].pb(4);
    adj[4].pb(3);
    findEuler_Path_Cycle();

    return 0;
}
