#include <bits/stdc++.h>
using namespace std;

struct Seg {
    int n;
    vector<int> t;
    Seg(int n): n(n), t(4*n, 0) {}
    int q(int v,int tl,int tr,int l,int r){
        if(l>r) return 0;
        if(l==tl && r==tr) return t[v];
        int tm=(tl+tr)/2;
        return max(q(v*2,tl,tm,l,min(r,tm)), q(v*2+1,tm+1,tr,max(l,tm+1),r));
    }
    void u(int v,int tl,int tr,int pos,int val){
        if(tl==tr){ t[v]=max(t[v],val); return; }
        int tm=(tl+tr)/2;
        if(pos<=tm) u(v*2,tl,tm,pos,val);
        else u(v*2+1,tm+1,tr,pos,val);
        t[v]=max(t[v*2],t[v*2+1]);
    }
    int query(int l,int r){ return q(1,0,n-1,l,r); }
    void update(int p,int val){ u(1,0,n-1,p,val); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<long long> h(n);
    for(int i=0;i<n;i++) cin>>h[i];

    vector<int> L(n,-1), R(n,n);
    {
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]<=h[i]) st.pop();
            L[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    }
    {
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]<h[i]) st.pop();
            R[i]=st.empty()?n:st.top();
            st.push(i);
        }
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int a,int b){
        if(h[a]==h[b]) return a<b;
        return h[a]<h[b];
    });

    Seg seg(n);
    vector<int> dp(n,1);

    for(int i=0;i<n;){
        int j=i;
        while(j<n && h[id[j]]==h[id[i]]) j++;
        for(int k=i;k<j;k++){
            int idx=id[k];
            int l=L[idx]+1;
            int r=R[idx]-1;
            int best = (l<=r) ? seg.query(l,r) : 0;
            dp[idx]=1+best;
        }
        for(int k=i;k<j;k++){
            seg.update(id[k], dp[id[k]]);
        }
        i=j;
    }

    int ans=0;
    for(int x:dp) ans=max(ans,x);
    cout<<ans<<"\n";
    return 0;
}
