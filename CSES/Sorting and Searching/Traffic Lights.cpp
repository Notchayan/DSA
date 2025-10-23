#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int x, n;
    cin >> x >> n;
    multiset<int> m;
    set<int> s;
    s.insert(0);
    s.insert(x);
    m.insert(x);
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        auto it = s.upper_bound(p);
        int r = *it;
        auto prev = --it;
        int l = *it;
        
        auto rm = m.find(r-l);
        
        
        // remove the already bracket 
        m.erase(rm);
        
        
        // then you will add the things in new bracket 
        
        s.insert(p);
        
        
        // left
        m.insert(p-l);
        
        // right
        m.insert(r-p);
        
        auto mini = *(m.rbegin());
        
        cout << mini << " ";
        
        
        
    }
}
 
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while(t--){
        solve();
    }
}