#include <bits/stdc++.h>
using namespace std;


class DSU {
    vector<int> par, sz;
public:
    DSU(int n) {
        par.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int find_set(int v) {
        if (par[v] == v) return v;
        return par[v] = find_set(par[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
};

int main() {


}
