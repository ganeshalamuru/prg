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
	int m,n;
    cin >> m;
    vector<vector<int>> seqbuild(m,vector<int>(3,-1));
    for(int i=0;i<m;i++) {
        cin >> seqbuild[i][0];
        if (seqbuild[i][0] == 1) {
            cin >> seqbuild[i][1];
        } else {
            cin >> seqbuild[i][1] >> seqbuild[i][2];
        }
    }
    cin >> n;
    vector<ll> reqinds(n);
    for(auto &i:reqinds)
        cin >> i;
    vector<ll> szs(m);
    szs[0] = 1;
    for(int i=1;i<m;i++) {
        if (seqbuild[i][0]==1) {
            szs[i]=szs[i-1] + 1;
        } else {
            szs[i] = szs[i-1] + 1ll*seqbuild[i][1]*seqbuild[i][2];
        }
    }
    for(int i=0;i<n;i++) {
        ll ind = reqinds[i];
        auto itr = lower_bound(szs.begin(), szs.end(), ind);
        int j = itr - szs.begin();
        while(seqbuild[j][0] != 1) {
            ll psz = szs[j-1];
            ind -= psz;
            ind = (ind-1)%(seqbuild[j][1]) + 1;
            itr = lower_bound(szs.begin(), szs.end(), ind);
            j = itr-szs.begin();
        }
        cout << seqbuild[j][1] << " ";
    }
    cout << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
