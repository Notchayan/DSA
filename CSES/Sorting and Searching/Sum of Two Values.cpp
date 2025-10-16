#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,x; 
    unordered_map<long long,int> m;
    for(int i=1;i<=n;i++){
        long long a; cin>>a;
        auto it=m.find(x-a);
        if(it!=m.end()){
            cout<<it->second<<" "<<i<<"\n";
            return 0;
        }
        if(!m.count(a)) m[a]=i;
    }
    cout<<"IMPOSSIBLE\n";
