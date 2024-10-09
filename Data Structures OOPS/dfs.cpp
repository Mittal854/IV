#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int node,unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans)
{
    ans.push_back(node);
    visited[node] = true;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,ans);
        }
    }
}

void print(vector<int> v)
{
    for(int i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    int v,e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<pair<int,int>> edges(e);
    cout << "Enter edges: ";
    for(int i = 0; i < e; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    // Making adjacency list

    unordered_map<int, list<int>> adj;
    for(auto edge: edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Adj list ban gye hai :}

    vector<int> ans;
    unordered_map<int,bool> visited;
    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,ans);
        }
    }
    print(ans);
    return 0;
}