#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    for(int i=0,a,b,c;i<m;i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<ll> dis(n+1, LLONG_MAX);
    set<pair<ll,ll>> ss;
    dis[1]=0;
    ss.insert({0,1});
    while (!ss.empty()) {
        auto [d,u] = *(ss.begin());
        ss.erase({d,u});
        for(auto &[v, c]:adj[u]) {
            if (dis[v]==LLONG_MAX) {
                dis[v]=d+c;
                ss.insert({dis[v],v});
            } else if (dis[v]>d+c) {
                ss.erase({dis[v],v});
                dis[v]=d+c;
                ss.insert({dis[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++) {
        cout << dis[i] << " ";
    }
    cout << "\n";


}


int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
