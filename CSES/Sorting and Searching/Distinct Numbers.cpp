#include <bits/stdc++.h>
using namespace std;
#define int long long
int LOG_CONS = 18;
 
void run(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i= 0; i<n; i++)cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 1;
    for(int i = 1; i < n; i++){
        ans += (a[i-1]!=a[i]);
    }
    cout << ans << endl;
}
 
int32_t main() {
    run();
}