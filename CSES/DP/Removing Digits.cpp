#include <bits/stdc++.h>
using namespace std;
#define int long long

void run(){
    int n;
    cin >> n;
    const int INF = 1e18;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for(int t = 1; t <= n; t++){
        int x = t;
        while(x > 0){
            int d = x % 10;
            x /= 10;
            if(d) dp[t] = min(dp[t], dp[t - d] + 1);
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
