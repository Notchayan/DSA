#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> cnt(n, 0);
    cnt[0] = 1;
 
    long long s = 0, ans = 0, v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        s += v;
        int r = (int)((s % n + n) % n);
        ans += cnt[r];
        cnt[r]++;
    }
    cout << ans << '\n';
    return 0;
}