#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n,s;
    cin>>n>>s;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int l=i+1,r=n-1;
        int tar=s-a[i].first;
        while(l<r){
            int sum=a[l].first+a[r].first;
            if(sum==tar){
                cout<<a[i].second<<" "<<a[l].second<<" "<<a[r].second<<"\n";
                return;
            }
            if(sum<tar) l++;
            else r--;
        }
    }
    cout<<"IMPOSSIBLE\n";
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T =1; 
    // cin>>T;
    while(T--) solve();
}
