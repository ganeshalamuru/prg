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


vector<ll> bit;

void update(int i, ll delta) {
    while(i<int(bit.size())) {
        bit[i]+=delta;
        i+=(i&-i);
    }
}

ll sum(int i) {
    ll sum = 0;
    while (i>0) {
        sum+=bit[i];
        i-=(i&-i);
    }
    return sum;
}

ll rangesum(int l, int r) {
    return sum(r)-sum(l-1);
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
    function<void(int,int)> dfs=[&](int u, int p) {
        dfstimes[u].F = ++dfstimer;
        for(int v:adj[u]) {
            if (v==p) continue;
            dfs(v,u);
        }
        dfstimes[u].S= dfstimer;
    };
    dfs(1,0);
    bit.resize(n+1,0);
    for(int i=1;i<=n;i++) {
        update(dfstimes[i].F,val[i]);
    }
    while (q--) {
        int t,s,x;
        cin >> t >> s;
        if (t==1) {
            cin >> x;
            update(dfstimes[s].F,x-val[s]);
            val[s]=x;
        } else {
            cout << rangesum(dfstimes[s].F,dfstimes[s].S) << "\n";
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
