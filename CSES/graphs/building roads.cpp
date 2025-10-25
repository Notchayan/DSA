#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;

// so basically I have to find the connected components and then connect them using some cities in each of them so 

vector<int> heads;
vector<int> visited;

void dfs(int u){
    visited[u]=1;
    for(int v : g[u]){
        if(visited[v]) continue;
        dfs(v);
    }
}

void run() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    visited.resize(n, 0);
    heads.clear();
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(visited[i])continue;
        heads.push_back(i);
        dfs(i);
    }
    cout << heads.size()-1 << endl;
    for(int i = 0; i < heads.size()-1; i++){
        cout << heads[i]+1  << " " << heads[i+1]+1 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
