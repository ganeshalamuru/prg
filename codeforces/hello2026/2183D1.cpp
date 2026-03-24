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



void solve() {
	int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> pa(n+1,0),dis(n+1,0);
    function<void(int,int)>dfs = [&](int u, int p) {
        pa[u]=p;
        for(int v:adj[u]) {
            if (v==p) continue;
            dis[v]=dis[u]+1;
            dfs(v,u);
        }
    };
    dfs(1,0);
    vector<int> numwithdis(n+1,0), numchildren(n+1,0);
    for(int i=1;i<=n;i++) {
        numwithdis[dis[i]]++;
        numchildren[pa[i]]++;
    }
    cout << max(*max_element(all(numwithdis)), (*max_element(all(numchildren))) +1) << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
