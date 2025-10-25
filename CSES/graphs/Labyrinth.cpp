#include <bits/stdc++.h>
using namespace std;
#define int long long

void run() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &s : g) cin >> s;
    pair<int,int> st, en;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (g[i][j] == 'A') st = {i,j};
        if (g[i][j] == 'B') en = {i,j};
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int,int>>> par(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> mv(n, vector<char>(m, 0));
    queue<pair<int,int>> q;
    q.push(st);
    vis[st.first][st.second] = 1;
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,-1,1,0};
    char ch[4] = {'D','L','R','U'};
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        if (make_pair(x,y) == en) break;
        for (int t = 0; t < 4; t++) {
            int nx = x + dx[t], ny = y + dy[t];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny]) continue;
            if (g[nx][ny] == '#') continue;
            vis[nx][ny] = 1;
            par[nx][ny] = {x,y};
            mv[nx][ny] = ch[t];
            q.push({nx,ny});
        }
    }
    if (vis[en.first][en.second]) {
        string ans;
        auto cur = en;
        while (cur != st) {
            ans.push_back(mv[cur.first][cur.second]);
            cur = par[cur.first][cur.second];
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n" << ans.size() << "\n" << ans << "\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
