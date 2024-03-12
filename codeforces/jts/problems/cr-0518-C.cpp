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
	int n,m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<set<pii>> rooks(n);
    for(int i=0,x,y;i<m;i++) {
        cin >> x >> y;
        x--,y--;
        edges[x].push_back(y);
    }
    for(int i=0;i<n;i++) {
        rooks[i].insert({100*i,100*i});
        for(int v:edges[i]) {
            rooks[i].insert({100*i+v,v*100+i});
            rooks[i].insert({100*i+v,i*100});
            rooks[v].insert({100*v+i,v*100+i});
            rooks[v].insert({100*v+i,100*v});
        }
    }
    for(int i=0;i<n;i++) {
        cout << rooks[i].size() << "\n";
        for(auto co:rooks[i])
            cout << co.F+1 << " " << co.S+1 << "\n"; 
    }
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
