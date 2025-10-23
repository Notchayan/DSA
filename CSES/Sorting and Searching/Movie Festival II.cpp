#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
 
    sort(a.begin(), a.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
        if (x.second != y.second) return x.second < y.second;
        return x.first < y.first;
    });
 
    multiset<int> s;
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        int st = a[i].first, en = a[i].second;
        auto it = s.upper_bound(st);
        if (it != s.begin()) {
            --it;
            s.erase(it);
            s.insert(en);
            ans++;
        } else if ((int)s.size() < k) {
            s.insert(en);
            ans++;
        }
    }
 
    cout << ans << "\n";
    return 0;
}