#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void run(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(x+1, LLONG_MAX);
    
    // min no of coins required to make this i -> dp[i]
    dp[0]=0;
    for(int t = 1; t <= x; t++){
        for(int c : coins){
            if(t-c>=0)
                dp[t] = min(dp[t-c]+1, dp[t]);
        }
    }
    cout << dp[x] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
