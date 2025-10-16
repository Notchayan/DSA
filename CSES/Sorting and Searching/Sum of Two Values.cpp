#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    if(!(cin >> n >> x)) return 0;

    unordered_map<long long, int> pos;
    pos.reserve(n * 2);

    for(int i = 1; i <= n; i++){
        long long a; 
        cin >> a;
        auto it = pos.find(x - a);
        if(it != pos.end()){
            cout << it->second << " " << i << "\n";
            return 0;
        }
        if(!pos.count(a)) pos[a] = i;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
