#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}




void solve(){
	int n,m,k;
    cin >> n >> m >> k;
    vector<int> time(n);
    for(int &i:time)
        cin >> i;
    vector<int> dependency(n,0),vis(n,0);
    vector<vector<int>> edges(n,vector<int>());
    for(int i=0,x,y;i<m;i++) {
        cin >> x >> y;
        x--,y--;
        edges[x].push_back(y);
        dependency[y]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq[2];
    ll startTime = LLONG_MAX;
    for(int i=0;i<n;i++) {
        if (dependency[i] == 0)
            vis[i] = 1,pq[0].push({time[i],i}),startTime = min(startTime, time[i]*1ll);
    }
    ll cur = 0, days = -1, lastQuestTime;
    while(!pq[cur].empty()) {
        lastQuestTime = LLONG_MIN;
        while(!pq[cur].empty()) {
            pair<int, int> pp = pq[cur].top();
            pq[cur].pop();
            lastQuestTime = max(lastQuestTime, 1ll*pp.first);
            for(int i=0;i<edges[pp.second].size();i++) {
                int nq = edges[pp.second][i];
                if (!vis[nq]) {
                    if (pp.first<=time[nq])
                        pq[cur].push({time[nq], nq});
                    else
                        pq[cur^1].push({time[nq], nq});
                }
            }
        }
        cur^=1;
        days++;
    }
    cout << lastQuestTime + days*k - startTime << "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
