#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int maxi = LLONG_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++) {cin >> a[i];
        
        maxi = max(maxi, a[i]);
        sum += a[i];
    }
    cout << max(2*maxi,sum) << endl;
    
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T =1; 
    // cin>>T;
    while(T--) solve();
}
