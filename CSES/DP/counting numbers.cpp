#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[20][11][2][2];

int solve(string &num, int pos, int prev, int tight, int leading0) {
    if (pos == (int)num.size()) return 1;
    int &u = dp[pos][prev][tight][leading0];
    if (u != -1) return u;
    int ans = 0;
    int limit = tight ? num[pos] - '0' : 9;
    for (int d = 0; d <= limit; d++) {
        if (!leading0 && d == prev) continue;
        ans += solve(num, pos + 1, d, tight && (d == limit), leading0 && (d == 0));
    }
    return u = ans;
}

int sol(int num) {
    string s = to_string(num);
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, 10, 1, 1);
}

void run() {
    int a, b;
    cin >> a >> b;
    cout << sol(b) - sol(a - 1) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
