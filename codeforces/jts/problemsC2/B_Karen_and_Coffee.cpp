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
	int n,k,q;
    cin >> n >> k >> q;
    vector<int> events(200002, 0);
    for(int i=0,l,r;i<n;i++) {
        cin >> l >> r;
        events[l]++;
        events[r+1]--;
    }
    vector<int> padmsum(200001,0);
    int sum = 0;
    for(int i=1;i<padmsum.size();i++) {
        sum+=events[i];
        padmsum[i] = padmsum[i-1] + (sum>=k);
    }
    for(int i=0,l,r;i<q;i++) {
        cin >> l >> r;
        cout << (padmsum[r]-padmsum[l-1]) << "\n";
    }
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
