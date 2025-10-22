#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), pos(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
 
    int ans = 1;
    for(int v = 1; v < n; v++) if(pos[v] > pos[v+1]) ans++;
 
    auto neighbors = [&](int x, vector<pair<int,int>>& out){
        if(x > 1) out.push_back({x-1, x});
        if(x < n) out.push_back({x, x+1});
    };
 
    while(m--){
        int i, j; 
        cin >> i >> j;
        if(i == j){
            cout << ans << "\n";
            continue;
        }
        int x = a[i], y = a[j];
 
        vector<pair<int,int>> pairs;
        pairs.reserve(6);
        neighbors(x, pairs);
        neighbors(y, pairs);
        sort(pairs.begin(), pairs.end());
        pairs.erase(unique(pairs.begin(), pairs.end()), pairs.end());
 
        for(auto p : pairs) if(pos[p.first] > pos[p.second]) ans--;
 
        swap(a[i], a[j]);
        swap(pos[x], pos[y]);
 
        for(auto p : pairs) if(pos[p.first] > pos[p.second]) ans++;
 
        cout << ans << "\n";
    }
    return 0;
}