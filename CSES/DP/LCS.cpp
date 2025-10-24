#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
 
void run() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
 
    
    cout << dp[n][m] << '\n';
 
    
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
 
    reverse(lcs.begin(), lcs.end());
    for (int x : lcs) cout << x << " ";
    cout << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) run();
 
    return 0;
}