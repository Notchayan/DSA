#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    int med = a[n/2];
    int cost = 0;
    for(int i = 0; i < n; i++){
        cost += abs(med-a[i]);
    }
    cout << cost << endl;
}
 
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while(t--){
        solve();
    }
}
