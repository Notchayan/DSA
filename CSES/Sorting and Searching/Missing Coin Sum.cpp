#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    if(!(cin >> n)) return 0;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    sort(a.begin(), a.end());
 
    long long res = 1;
    for(long long v : a) {
        if(v > res) break;
        res += v;
    }
    cout << res << "\n";
    return 0;
}
