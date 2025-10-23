#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    unordered_map<int,int> last;
    int ans = 0, left = 0;
    for(int i = 0; i < n; i++){
        int v = a[i];
        if(last.count(v) && last[v] >= left) left = last[v] + 1;
        last[v] = i;
        ans += i - left + 1;
    }
    cout << ans << '\n';
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
