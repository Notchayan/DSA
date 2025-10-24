#include <bits/stdc++.h>
using namespace std;
 

void run() {
    int n;
    cin >> n;
    vector<int> c(n);
    for(int &i : c) cin >> i;
    int sum = 0;
    for(int i : c){
        sum += i;
    }
    vector<int> dp(sum+1, 0);
    dp[0]=1;
    for(int coin : c){
        for(int i = sum; i >= 1; i--){
            if(i-coin>=0){
                if(dp[i-coin]==1){
                    dp[i] = 1;
                    continue;
                }
            }
        }
    }
    int ans = 0;
    vector<int> out;
    for(int i = 1; i <= sum; i++){
        if(dp[i]==1){
            ans++;
            out.push_back(i);
        }
    }
    cout << out.size() << endl;
    
    for(int i : out){
        cout << i << " ";
    }
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}