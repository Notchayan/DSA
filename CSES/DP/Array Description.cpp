#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
 
void run() {
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int> (m+1, 0));
    // this dp is just number of ways for that number at that position 
    vector<int> a(n);
    for(int &i : a) cin >> i;
    if(a[0]==0){
        for(int i = 1; i <= m; i++){
            dp[0][i]=1;
        }
    }else{
        dp[0][a[0]] = 1;
    }
    for(int i = 1; i < n; i++){
        // just you have to update the current value 
        // from previous results 
        int val = a[i];
        if(val == 0){
            for(int t = 1; t <= m; t++){
                dp[i][t] += dp[i-1][t];
                dp[i][t] %= MOD;
                if(t-1>=1)
                    dp[i][t] += dp[i-1][t-1];
                dp[i][t] %= MOD;
                if(t+1<=m)
                    dp[i][t] += dp[i-1][t+1];
                dp[i][t] %= MOD;
            }
        }else{
            dp[i][val] += dp[i-1][val];
            dp[i][val] %= MOD;
            if(val-1>=1)
                dp[i][val] += dp[i-1][val-1];
            dp[i][val] %= MOD;
            if(val+1<=m)
                dp[i][val] += dp[i-1][val+1];
            dp[i][val] %= MOD;
        }
    }
    int val = a[n-1];
    int ans = 0;
    if(val==0){
        for(int t = 1; t <= m; t++){
            ans += dp[n-1][t];
            ans %= MOD;
        }
    }else{
        ans += dp[n-1][val];
        ans %= MOD;
    }
    cout << ans << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) run();
 
    return 0;
}
