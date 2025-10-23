#include <bits/stdc++.h>
using namespace std;
 
 
struct BIT{
    int n; vector<int> f;
    BIT(int n=0): n(n), f(n+1,0){}
    void add(int i,int v){ for(; i<=n; i+=i&-i) f[i]+=v; }
    int sumPrefix(int i){ int s=0; for(; i>0; i-=i&-i) s+=f[i]; return s; }
    int sumRange(int l,int r){ if(r<l) return 0; return sumPrefix(r)-sumPrefix(l-1); }
};
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; 
    if(!(cin>>n)) return 0;
    vector<array<int,3>> a(n);
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        a[i]={x,y,i};
    }
    auto cmp = [&](const array<int,3>& A, const array<int,3>& B){
        if(A[0]!=B[0]) return A[0]<B[0];
        return A[1]>B[1];
    };
    sort(a.begin(), a.end(), cmp);
 
    vector<int> allR; allR.reserve(n);
    for(auto &t:a) allR.push_back(t[1]);
    sort(allR.begin(), allR.end());
    allR.erase(unique(allR.begin(), allR.end()), allR.end());
    auto rid = [&](int r){ return int(lower_bound(allR.begin(), allR.end(), r)-allR.begin())+1; };
    int m = (int)allR.size();
 
    vector<int> contains(n,0), containedBy(n,0);
 
    // containedBy: count of intervals that contain this one
    {
        BIT bit(m);
        for(int i=0;i<n;i++){
            int r = a[i][1], id = a[i][2];
            int idx = rid(r);
            int seen = i; // number of previous intervals
            int prevWithRge = bit.sumRange(idx, m);
            containedBy[id] = prevWithRge;
            bit.add(idx,1);
        }
    }
 
    // contains: count of intervals this one contains
    {
        BIT bit(m);
        for(int i=n-1;i>=0;i--){
            int r = a[i][1], id = a[i][2];
            int idx = rid(r);
            int cnt = bit.sumPrefix(idx);
            contains[id] = cnt;
            bit.add(idx,1);
        }
    }
 
    for(int i=0;i<n;i++){
        cout<<contains[i]<<(i+1==n?'\n':' ');
    }
    for(int i=0;i<n;i++){
        cout<<containedBy[i]<<(i+1==n?'\n':' ');
    }
    return 0;
}