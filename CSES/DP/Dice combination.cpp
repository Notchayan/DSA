#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000007;

void run(){
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int t = 1; t <= n; t++){
        for(int i = 1; i <= 6; i++){
            if(t - i >= 0){
                dp[t] += dp[t - i];
                if(dp[t] >= MOD) dp[t] -= MOD;
            }
        }
    }
    cout << dp[n] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
