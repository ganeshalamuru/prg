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


vector<int> bit;

void update(int i, int val) {
    if (i<=0) return;
    while (i<int(bit.size())) {
        bit[i]+=val;
        i+=(i&-i);
    }
}

int sum(int l, int r) {
    int ans = 0;
    while (r>0) {
        ans+=bit[r];
        r-=(r&-r);
    }
    l--;
    while (l>0) {
        ans-=bit[l];
        l-=(l&-l);
    }
    return ans;
}
// can also be solved by small-to-large merging idea, check usaco guide
void solve() {
	int n;
    cin >> n;
    vector<int> color(n+1);
    for(int i=1;i<=n;i++) {
        cin >> color[i];
    }
    vector<vector<int>> adj(n+1);
    for(int a,b,i=1;i<n;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<array<int,3>> dfstimes(n+1);
    vector<int> dfstimetocolor(n+1); 
    int dfstimer = 0;
    function<void(int,int)> dfs = [&](int u,int p) {
        dfstimes[u][0] = ++dfstimer;
        dfstimetocolor[dfstimer]=color[u];
        for(int v:adj[u]) {
            if (v==p) continue;
            dfs(v,u);
        }
        dfstimes[u][1] = dfstimer;
        dfstimes[u][2]=u;
    };
    dfs(1,0);
    sort(dfstimes.begin()+1, dfstimes.end(),[&](const auto &a, const auto &b) {
        return a[1]<b[1];
    });
    bit.resize(n+1);
    int i=1,j=1;
    map<int,int> lastcolordfstime;
    vector<int> ans(n+1);
    while(i<=n) {
        while(j<=dfstimes[i][1]) {
            int colr = dfstimetocolor[j];
            int &lastctime = lastcolordfstime[colr];
            update(lastctime,-1);
            update(j,1);
            lastcolordfstime[colr]=j;
            j++;
        }
        ans[dfstimes[i][2]] = sum(dfstimes[i][0], dfstimes[i][1]);
        i++;
    }

    for(int z=1;z<=n;z++) {
        cout << ans[z] << " ";
    }
    cout << "\n";

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
