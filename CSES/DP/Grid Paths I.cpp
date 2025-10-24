#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
 
void run() {
   int n;
   cin >> n;
   vector<vector<char>> matrix(n, vector<char> (n));
   for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           cin >> matrix[i][j];
       }
   }
   vector<vector<int>> dp(n, vector<int>(n, 0));
   for(int i = 0; i < n; i++) if(matrix[i][0]=='.') dp[i][0]=1; else break;
   for(int i = 0; i < n; i++) if(matrix[0][i]=='.') dp[0][i]=1; else break;
   for(int i = 1; i < n; i++){
       for(int j = 1; j < n; j++){
           if(matrix[i][j]=='.'){
               dp[i][j]+=dp[i-1][j];
               dp[i][j]%=MOD;
               dp[i][j]+=dp[i][j-1];
               dp[i][j]%=MOD;
           }
       }
   }
   cout <<dp[n-1][n-1] << endl;
   
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) run();
 
    return 0;
}
