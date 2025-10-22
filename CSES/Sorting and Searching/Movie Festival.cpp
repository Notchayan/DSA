#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
 
    sort(v.begin(), v.end(), 
         [](const pair<long long, long long>& x, const pair<long long, long long>& y) {
             return x.second < y.second;
         });
 
    long long last = 0, ans = 0;
    for (auto &p : v) {
        if (p.first >= last) {
            ans++;
            last = p.second;
        }
    }
    cout << ans << "\n";
    return 0;
}
