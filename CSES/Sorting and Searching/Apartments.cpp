#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
void run(){
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   vector<int> b(m);
   for(int i = 0; i < m; i++) cin >> b[i];
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   
   int ans = 0;
   int i = 0;
   int j = 0;
   
   while(i < n && j < m){
       if(abs(a[i]-b[j])<=k){
           i++;
           j++;
           ans++;
       }else if(a[i]-b[j]>k){
           // b[j] is too small for it 
           j++;
       }else if(b[j]-a[i]>k){
           // b[j] is too big for it 
           i++;
       }
   }
   cout << ans << endl;
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--) run();
    return 0;
}