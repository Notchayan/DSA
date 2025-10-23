#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; 
    if(!(cin>>n>>k)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
 
    unordered_map<long long,int> cnt;
    long long ans=0;
    int distinct=0;
    int l=0;
    for(int r=0;r<n;r++){
        if(++cnt[a[r]]==1) distinct++;
        while(distinct>k){
            if(--cnt[a[l]]==0){ cnt.erase(a[l]); distinct--; }
            l++;
        }
        // number of subarrays ending at r 
        ans += r - l + 1;
    }
    cout<<ans<<"\n";
    return 0;
}