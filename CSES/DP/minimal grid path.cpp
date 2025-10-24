#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<string> grid;
 
void run() {
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
 
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
 
    string result = "";
    result += grid[0][0];
 
    for (int step = 1; step <= 2 * n - 2; ++step) {
        char minChar = 'Z' + 1;
        vector<pair<int, int>> next;
 
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
 
            for (auto [nx, ny] : vector<pair<int, int>>{{x + 1, y}, {x, y + 1}}) {
                if (nx < n && ny < n && !visited[nx][ny]) {
                    if (grid[nx][ny] < minChar) {
                        minChar = grid[nx][ny];
                        next.clear();
                        next.push_back({nx, ny});
                    } else if (grid[nx][ny] == minChar) {
                        next.push_back({nx, ny});
                    }
                    visited[nx][ny] = true;
                }
            }
        }
 
        result += minChar;
        for (auto p : next) q.push(p);
    }
 
    cout << result << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}