#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
#include<queue>
using namespace std;

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &ans,int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);


        for(auto i : adjList[frontNode]){
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}


int main() 
{
    int n,m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<pair<int,int>> edges(m);
    for(int i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    
    // Prepare adjacency list
    unordered_map<int, set<int>> adjList;
    for(auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    // AdjList ban gaye hai.

    // Creating visited variable to keep track of visited nodes.
    unordered_map<int,bool> visited;

    vector<int> ans; // Final answer 

    // traverse all components of graph

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            bfs(adjList,visited,ans,i);
        }
    }
    for(auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}