#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
 
void run() {
    int n;
    cin >> n;
    int pmax;
    cin >> pmax;
    vector<int> dp(pmax+1, 0);
    vector<int> price(n);
    vector<int> pages(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
    for(int i = 0; i < n; i++){
        for(int p = pmax; p>= 0; p--){
            if(p-price[i]>=0){
                dp[p] = max(dp[p], dp[p-price[i]]+pages[i]);
            }
        }
    }
    cout << dp[pmax] << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) run();
 
    return 0;
}
