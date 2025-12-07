#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;

int max_compsz,num_comp;
// dsu union with size with path compression
vector<int> dsu_pa,dsu_size;
void init_dsu(int n) {
    dsu_pa.resize(n+1);
    dsu_size.resize(n+1);
    for(int i=1;i<=n;i++) {
        dsu_pa[i]=i;
        dsu_size[i]=1;
    }
    max_compsz=1;
    num_comp=n;
}
int find_root(int u) {
    if (dsu_pa[u]==u)
        return  u;
    return dsu_pa[u] = find_root(dsu_pa[u]);
}

void dsu_union(int u, int v) {
    int u_root = find_root(u);
    int v_root = find_root(v);
    if (u_root==v_root)
        return;
    if (dsu_size[u_root] < dsu_size[v_root]) {
        swap(u_root,v_root);
    }
    dsu_pa[v_root]=u_root;
    num_comp--;
    dsu_size[u_root]+=dsu_size[v_root];
    max_compsz=max(max_compsz,dsu_size[u_root]);
}

void solve() {
	int n,m;
    cin >> n >> m;
    init_dsu(n);
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        dsu_union(a,b);
        cout << num_comp << " " << max_compsz << "\n";
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
