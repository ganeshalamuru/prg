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
    vector<vector<ll>> dis(n+1,vector<ll>(2,LLONG_MAX));
    set<array<ll,3>> ss;
    dis[1][0]=0,dis[1][1]=0;
    ss.insert({dis[1][0],1,0});
    ss.insert({dis[1][1],1,1});
    while(!ss.empty()) {
        auto [d,u,used]=*(ss.begin());
        ss.erase({d,u,used});
        for(auto &[v,c]:adj[u]) {
            // no discount used
            if (dis[v][used]==LLONG_MAX) {
                dis[v][used]=d+c;
                ss.insert({dis[v][used],v,used});
            } else if (dis[v][used]>d+c) {
                ss.erase({dis[v][used],v,used});
                dis[v][used]=d+c;
                ss.insert({dis[v][used],v,used});
            }

            // try to use discount
            if (used==0) {
                if (dis[v][1]==LLONG_MAX) {
                    dis[v][1]=d+c/2;
                    ss.insert({dis[v][1],v,1});
                } else if (dis[v][1]>d+c/2) {
                    ss.erase({dis[v][1],v,1});
                    dis[v][1]=d+c/2;
                    ss.insert({dis[v][1],v,1});
                }
            }

        }
    }
    cout << min(dis[n][0],dis[n][1]) << "\n";
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
