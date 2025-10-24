#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

void run(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int &i : c) cin >> i;
    vector<int> dp(x+1, 0);
    dp[0]=1;
    for(int i : c){
    for(int t = 1; t <= x; t++){
            if(t-i>=0){
                dp[t] += dp[t-i];
                dp[t] %= MOD;
            }
        }
    }
    dp[x] %= MOD;
    cout << dp[x] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
