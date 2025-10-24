#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

void run(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // basically I have to solve it like 
    // this is very random to make it using sorting or some other logic 
    
    // so basically I have will use all the masks 
    
    // as n < 20 
    
    // so for all the masks 
    
    // 0011101101 -> I have to add make this using the pre masks so i will try to make this using other previous masks 
    
    
    // so basically I will use the 000101100101001 -> from all the previous masks 
    
    // for the dp I will store the dp[mask] -> storing the number of rides 
    // that will be min number of rides and weight used in the last edition 
    
    // 1<<n = 2^n so it is 000000001 not 11111111
    vector<pair<int,int>> dp(1<<n, {INF, INF});
    // how to take 0 people with -> 1 ride with 0 weight in that 
    dp[0] = {1, 0};
    for(int mask = 1; mask < (1<<n); mask++){
        for(int i = 0; i < n; i++){
            if((mask>>i)&1){
                // so basically not including the 1<<i
                int prev = mask^(1<<i);
                auto [rides, ls] = dp[prev];
                if(ls+a[i] <= x){
                    dp[mask] = min(dp[mask], {rides, ls+a[i]});
                }else{
                    dp[mask] = min(dp[mask], {rides+1, a[i]});
                }
            }
        }
    }
    // all one mask 
    int maskmax = (1<<n)-1;
    cout << dp[maskmax].first << endl;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
