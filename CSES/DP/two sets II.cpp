#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
 
// Fast exponentiation
int modinv(int a, int mod) {
    int res = 1, b = mod - 2;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
int32_t main() {
    int n;
    cin >> n;
 
    int total = n * (n + 1) / 2;
    if (total % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }
 
    int target = total / 2;
    vector<int> dp(target + 1);
    dp[0] = 1;
 
    for (int x = 1; x <= n; ++x) {
        for (int i = target; i >= x; --i) {
            dp[i] = (dp[i] + dp[i - x]) % MOD;
        }
    }
 
    // Since each valid partition is counted twice, divide by 2 using modular inverse
    // so basically mutliy by the (2^Mod-2)%MOD
    cout << dp[target] * modinv(2, MOD) % MOD << '\n';
    return 0;
}
