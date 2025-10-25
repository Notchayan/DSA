#include <bits/stdc++.h>
using namespace std;
#define int long long
 
vector<vector<int>> g;
vector<int> vis;
bool found = false;
vector<int> parent;
int node;
 
void dfs(int u, int par){
    vis[u]=1;
    parent[u]=par;
    for(int v : g[u]){
        if(found) continue;
        if(vis[v]==1 && v != par){
            parent[v]=u;
            node = v;
            found = true;
        }
        if(v != par && vis[v]==0){
            dfs(v, u);
        }
    }
}
 
 
 
void run() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    vis.resize(n, 0);
    parent.resize(n);
    node = -1;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    
    if(node==-1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    vector<int> path;
    int curr = node;
    path.push_back(curr);
    curr = parent[curr];
    while(curr != node){
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(curr);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for(int i : path){
        cout << i+1 << " ";
    }
    cout << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) run();
}
