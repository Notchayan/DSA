#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
void run(){
   int n, x;
   cin >> n >> x;
   vector<int> a(n);
   for(int i = 0; i < n; i++){
       cin >> a[i];
   }
   sort(a.begin(), a.end());
   int i = 0;
   int j = n-1;
   int ans = 0;
   while(i<=j){
       if(a[i]+a[j]<=x){
           ans++;
           i++;
           j--;
       }else{
           j--;
           ans++;
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