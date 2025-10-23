#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void run(){
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
        // come , goback 
        a[i][2]=i;
    }
    auto cmp = [](array<int, 3> a1, array<int, 3> a2){
        return a1[0] < a2[0]; 
    };
    sort(a.begin(), a.end(), cmp);
    // so come ealier to get the room 
    
    vector<int> ans(n);
    
    int last_room = 0;
    
    // min heap to store the departure and room used by it 
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // go and the room used 
 
    for(int i = 0; i < n; i++){
        array<int, 3> use = a[i];
        // first case will be like you have to take up a new room only 
        if(pq.size() == 0 || pq.top().first >= use[0]){
            last_room++;
            ans[use[2]]=last_room;
            pq.push({use[1], last_room});
        }else{
            // so basically I can reuse the room now 
            // of the top person 
            auto [u, room] = pq.top(); 
            pq.pop();
            ans[use[2]] = room;
            pq.push({use[1], room});
        }
    }   
    
    
    // this is the numnber of rooms 
    cout << last_room << endl;
    
    for(int i = 0; i < n; i++){
        // these are the markers of the room they used 
        cout << ans[i] << " ";
    }
    
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while(T--) run();
    return 0;
