#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    multiset<int> s;
    for(int i = 0; i < n; i++){
        int u = a[i];
        auto it = s.upper_bound(u);
        if(it != s.end()) s.erase(it);
        s.insert(u);
    }
    cout << s.size() << endl;
}
 
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while(t--){
        solve();
    }
}
