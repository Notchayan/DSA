#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
 
void solve(){
    int n; 
    cin >> n;
    unordered_map<int,int> f;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        f[x]++;
    }
    long long ans = 1;
    for(auto &kv : f){
        ans = (ans * (kv.second + 1)) % MOD;
    }
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << '\n';
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
