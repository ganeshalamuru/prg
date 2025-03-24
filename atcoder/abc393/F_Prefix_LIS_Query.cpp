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




void solve() {
	int n,q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    vector<vector<int>> queries;
    for(int i=0;i<q;i++) {
        int r,x;
        cin >> r >> x;
        r--;
        queries.push_back({r,x,i});
    }
    sort(queries.begin(), queries.end());
    int j=1;
    set<pii> ss;
    ss.insert({a[0],1});
    vector<int>ans(q);
    for(int i=0;i<q;i++) {
        int r = queries[i][0],x=queries[i][1];
        while(j<=r) {
            auto itr = ss.lower_bound({a[j],0});
            auto titr = itr;
            int len = 1;
            if (titr!=ss.begin())
                titr--,len+=titr->second;
            vector<pii> todelete;
            while(itr!=ss.end() && a[j]<=itr->first && len>=itr->second)
                todelete.push_back(*itr),itr++;
            for(auto &pp:todelete)
                ss.erase(pp);
            ss.insert({a[j],len});
            j++;
        }
        auto itr = ss.lower_bound({x+1,0});
        itr--;
        ans[queries[i][2]]=itr->second;
    }
    for(int i=0;i<q;i++)
        cout << ans[i] << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
