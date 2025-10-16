#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int sum = a[0];
    int msum = a[0];
    for (int i = 1; i < n; i++) {
        sum = max(a[i], sum + a[i]);
        msum = max(msum, sum);
    }

    cout << msum << "\n";
    return 0;
}
