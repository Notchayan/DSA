#include <bits/stdc++.h>
using namespace std;
 
bool ok(long long mid, int k, const vector<long long>& a){
    long long s = 0;
    int groups = 1;
    for(long long x : a){
        if(x > mid) return false;
        if(s + x > mid){
            groups++;
            s = x;
        }else{
            s += x;
        }
    }
    return groups <= k;
}
 
void solve(){
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long lo = *max_element(a.begin(), a.end());
    long long hi = accumulate(a.begin(), a.end(), 0LL);
    while(lo < hi){
        long long mid = lo + (hi - lo) / 2;
        if(ok(mid, k, a)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
