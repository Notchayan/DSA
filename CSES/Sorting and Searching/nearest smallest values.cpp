#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> ans(n);
    vector<pair<long long,int>> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.back().first >= a[i]) st.pop_back();
        ans[i] = st.empty() ? 0 : st.back().second;
        st.push_back({a[i], i + 1});
    }
    
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
