#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    if(!(cin >> n)) return 0;
    vector<pair<long long,int>> e;
    e.reserve(2*n);
    for(int i=0;i<n;i++){
        long long a,b; cin >> a >> b;
        e.push_back({a, +1});
        e.push_back({b, -1});
    }
    sort(e.begin(), e.end());
    long long cur = 0, ans = 0;
    for(auto &p: e){
        cur += p.second;
        if(cur > ans) ans = cur;
    }
    cout << ans << "\n";
    return 0;
}