#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,i,u,v;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for(i = 1; i <= m; ++i){
        cin >> u >> v; 
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    if(adj[1].size() == 0){
        cout << "IMPOSSIBLE\n";
    }
    else{
         vector<bool> visited(n+1, false);
    queue<int> q; 
    visited[1] = true; 
    q.push(1); 
    vector<int> prev(n+1, -1);
    prev[1] = -1; 

    while(!q.empty()){
        int curNode = q.front();
        q.pop();
        for(auto node: adj[curNode]){
            if(!visited[node]){
                visited[node] = true; 
                q.push(node); 
                prev[node] = curNode;
            }
        }
    }
    if(prev[n] == -1) cout << "IMPOSSIBLE\n";
    else{
         vector<int> path; 
    int curNode = n; 
    
    while(prev[curNode] != -1){
        path.emplace_back(curNode);
        curNode = prev[curNode];
    }

    path.emplace_back(1);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for(auto p : path) cout << p << " "; 
    }
   
    }
   
    return 0;
}