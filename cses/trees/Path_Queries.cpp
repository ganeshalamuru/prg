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

vector<ll>bit;


void update(int l, int r, ll delta) {
    while(l<int(bit.size())) {
        bit[l]+=delta;
        l+=(l&-l);
    }
    r++;
    while (r<int(bit.size())) {
        bit[r]-=delta;
        r+=(r&-r);
    }
}

ll sum(int i) {
    ll ans = 0;
    while (i>0) {
        ans+=bit[i];
        i-=(i&-i);
    }
    return ans;
}

void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> val(n+1);
    for(int i=1;i<=n;i++) {
        cin >> val[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i=1,a,b;i<n;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pii> dfstimes(n+1);
    int dfstimer = 0;
    function<void(int,int)> dfs = [&](int u, int p) {
        dfstimes[u].F = ++dfstimer;
        for(int v:adj[u]) {
            if (v==p) continue;
            dfs(v,u);
        }
        dfstimes[u].S = dfstimer;
    };
    dfs(1,0);
    bit.resize(n+1,0);
    for(int i=1;i<=n;i++) {
        update(dfstimes[i].F,dfstimes[i].S,val[i]);
    }
    while (q--) {
        int t,s,x;
        cin >> t >> s;
        if (t==1) {
            cin >> x;
            update(dfstimes[s].F,dfstimes[s].S,x-val[s]);
            val[s]=x;
        } else {
            cout << sum(dfstimes[s].F) << "\n";
        }
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
