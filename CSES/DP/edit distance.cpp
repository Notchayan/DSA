#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
 
 
void run() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    dp[0][0]=0;
    for(int i = 0; i <= n; i++){
        dp[i][0]=i;
    }
    for(int i = 0; i <= m ; i++){
        dp[0][i]=i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
            }
        }
    }
    cout << dp[n][m] << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) run();
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
 
 
void run() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    dp[0][0]=0;
    for(int i = 0; i <= n; i++){
        dp[i][0]=i;
    }
    for(int i = 0; i <= m ; i++){
        dp[0][i]=i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
            }
        }
    }
    cout << dp[n][m] << endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) run();
 
    return 0;
}
