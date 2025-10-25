#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> team;
bool no = false;

void dfs(int u, int t){
    team[u] = t;
    t = 3-t;
    for(int v : g[u]){
        if(team[v]==0){
            dfs(v, t);
            continue;
        }
        if(team[v]!=t){
            no = true;
        }
    }
}

void run() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    team.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(team[i]==0)
        dfs(i,1);
    }
    
    if(no){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    for(int i = 0; i < n; i++){
        cout << team[i] << " ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
