#include <bits/stdc++.h>
using namespace std;
#define int long long

void run(){
    int n;
    cin >> n;
    vector<array<int,3>> pro(n);
    for(int i = 0; i < n; i++){
        // start , end , reward
        cin >> pro[i][0] >> pro[i][1] >> pro[i][2];
    }
    auto cmp = [&](array<int,3> a1, array<int,3> a2){
        return a1[1] < a2[1]; 
    };
    // sort by end
    sort(pro.begin(), pro.end(), cmp);
    map<int,int> dp;
    dp[0]=0;
    for(int i = 0; i < n; i++){
        auto [start, end, reward] = pro[i];
        // i will look for sequence of project with end of that < start of this 
        // then consider it only when the total is max for all the things with ending less then this ending 
        // since it is the lastest ending so it will be the max ending 
        // so I need the dp  
        // in which I can find the last element with end < start of this 
        // end find the max till now 
        auto it = dp.lower_bound(start);
        it--;
        int tot = it->second + reward;
        int max = dp.rbegin()->second;
        if(tot > max){
            dp[end] = tot;
        }
    }
    int max = dp.rbegin()->second;
    cout << max << endl;
    
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}
