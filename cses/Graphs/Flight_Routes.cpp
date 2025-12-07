#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,m,k;
    cin >> n >> m >> k;
    vector<vector<array<int,2>>> adj(n+1);
    for(int i=0,a,b,c;i<m;i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<vector<ll>> dis(k,vector<ll>(n+1,LLONG_MAX));
    vector<int> kthdiscompleted(n+1,0);
    vector<multiset<ll,greater<ll>>> nodedisinq(n+1);
    multiset<array<ll,2>> ss;
    ss.insert({0,1});
    nodedisinq[1].insert(0);
    while(dis[k-1][n]==LLONG_MAX) {
        auto itr = ss.begin();
        auto [d, u]=*itr;
        dis[kthdiscompleted[u]][u]=d;
        kthdiscompleted[u]++;
        nodedisinq[u].erase(nodedisinq[u].find(d));
        ss.erase(itr);
        for(auto &[v,c]:adj[u]) {
            if (kthdiscompleted[v]+int(nodedisinq[v].size())<k) {
                ss.insert({d+c,v});
                nodedisinq[v].insert(d+c);
            } else if (kthdiscompleted[v]<k && (nodedisinq[v].empty() || d+c < (*nodedisinq[v].begin()))) {
                if (!nodedisinq.empty()) {
                    auto vitr = nodedisinq[v].begin();
                    ss.erase(ss.find({*vitr,v}));
                    nodedisinq[v].erase(vitr);
                }
                ss.insert({d+c,v});
                nodedisinq[v].insert(d+c);
            }
        }
    }
    for(int i=0;i<k;i++) {
        cout << dis[i][n] << " ";
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
