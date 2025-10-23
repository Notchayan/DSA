#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
void run(){
   int n;
   cin >> n;
   vector<array<int,2>> a(n);
   for(int i = 0; i < n; i++){
       cin >> a[i][0] >> a[i][1];
       // duration , deadline
   }
   
   auto cmp = [](array<int, 2> a1, array<int, 2> a2){
       return a1[0] < a2[0];
   };
   
   sort(a.begin(), a.end(), cmp);
   
   int ans = 0;
   int sum = 0;
   for(auto each : a){
       sum += each[0];
       ans += each[1] - sum;
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