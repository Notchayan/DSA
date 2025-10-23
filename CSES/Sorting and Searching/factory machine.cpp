#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; long long t;
    if(!(cin >> n >> t)) return 0;
    vector<long long> k(n);
    long long mn = LLONG_MAX;
    for(int i = 0; i < n; i++){
        cin >> k[i];
        mn = min(mn, k[i]);
    }
    long long lo = 0, hi = mn * t; 
    while(lo < hi){
        long long mid = lo + (hi - lo) / 2;
        __int128 made = 0;
        for(long long ki : k){
            made += mid / ki;
            if(made >= t) break;
        }
        if(made >= t) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
    return 0;
}
