#include <bits/stdc++.h>
using namespace std;
#define int long long

void run() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') continue;
            if (vis[i][j]) continue;
            cnt++;

            queue<pair<int,int>> q;
            q.push({i, j});
            vis[i][j] = 1;

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int t = 0; t < 4; t++) {
                    int nx = x + dx[t];
                    int ny = y + dy[t];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny]) continue;
                    if (grid[nx][ny] == '#') continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << cnt << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
