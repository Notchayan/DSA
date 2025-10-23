#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    unordered_map<long long, long long> cnt;
    cnt[0] = 1;
 
    long long presum = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        presum += a[i];
        ans += cnt[presum - x];
        cnt[presum]++;
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
