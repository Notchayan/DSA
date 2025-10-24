#include <bits/stdc++.h>
using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            int tot = pre[j] - (i > 0 ? pre[i - 1] : 0);
            dp[i][j] = tot - min(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
