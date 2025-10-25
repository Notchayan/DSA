#include <bits/stdc++.h>
using namespace std;
#define int long long


void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> par(n);
    vector<int> visited(n,0);
    
    // I will do bfs
    queue<int> q;
    q.push(0);
    visited[0]=1;
    
    while(q.size()>0){
        int u = q.front(); q.pop();
        
        for(int v : g[u]){
            if(visited[v]) continue;
            par[v]=u;
            visited[v]=1;
            q.push(v);
        }
    }
    
    int ed = n-1;
    
    
    if(visited[ed]==0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> path;
    while(ed != 0){
        path.push_back(ed);
        ed = par[ed];
    }
    path.push_back(0);
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for(int i : path){
        cout << i+1 << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
