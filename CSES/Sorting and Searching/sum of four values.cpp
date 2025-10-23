#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n, x;
    if(!(cin >> n >> x)) return;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    unordered_map<long long, pair<int,int>> mp; // sum -> indices (k, i) with k < i
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            long long need = x - (a[i] + a[j]);
            auto it = mp.find(need);
            if(it != mp.end()){
                auto [p, q] = it->second; // p < q < i < j
                cout << p + 1 << " " << q + 1 << " " << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
        for(int k = 0; k < i; k++){
            mp[a[k] + a[i]] = {k, i};
        }
    }
    cout << "IMPOSSIBLE\n";
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
