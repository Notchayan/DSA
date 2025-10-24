#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int INF = 1e18;
 
void run() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int> (b+1, INF));
    
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
            }
            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
            }
        }
    }
    
    cout << dp[a][b] << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) run();
 
    return 0;
}