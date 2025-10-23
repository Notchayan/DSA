#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
 
void solve(){
    int n;
    cin >> n;
    vector<array<int, 3>> v(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[i] = {a,b,i};
    }
    auto cmp = [&](array<int,3> a1, array<int, 3> a2){
        if(a1[0]!=a2[0]) return a1[0] < a2[0];
        return a1[1] > a2[1];
    };
    sort(v.begin(), v.end(), cmp);
    //conti
    vector<int> contained(n, 0);
    int r = -1;
    int maxr = LLONG_MIN;
    int id = -1;
    for(int i = 0; i < n; i++){
        r = v[i][1]; id = v[i][2];
        if(r<=maxr) contained[id] = 1;
        maxr = max(maxr, r);
    }
    int mnr = LLONG_MAX;
    vector<int> contains(n, 0);
    for(int i = n-1; i>= 0; i--){
        r = v[i][1]; id = v[i][2];
        if(mnr<=r) contains[id] = 1;
        mnr = min(mnr, r);
    }
    
    for(int i = 0; i < n; i++){
        cout << contains[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << contained[i] << " ";
    }
    cout << endl;
    
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}