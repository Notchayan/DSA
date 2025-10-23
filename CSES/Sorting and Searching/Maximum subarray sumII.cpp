#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,a,b;
    if(!(cin>>n>>a>>b)) return 0;
    vector<long long> x(n), p(n+1,0);
    for(int i=0;i<n;i++){
        cin>>x[i];
        p[i+1]=p[i]+x[i];
    }
    multiset<long long> s;
    long long ans = LLONG_MIN;
    for(int i=a;i<=n;i++){
        s.insert(p[i-a]);
        if(i-b-1>=0){
            auto it=s.find(p[i-b-1]);
            if(it!=s.end()) s.erase(it);
        }
        ans=max(ans,p[i]-*s.begin());
    }
    cout<<ans<<"\n";
    return 0;
}
