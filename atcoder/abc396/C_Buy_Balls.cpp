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
	int n,m;
    cin >> n >> m;
    vector<int> b(n),w(m);
    for(int i=0;i<n;i++)
        cin >> b[i];
    for(int j=0;j<m;j++)
        cin >> w[j];
    sort(b.rbegin(),b.rend());
    sort(w.rbegin(), w.rend());
    int i=0,j=0;
    ll ans = 0;
    while(j<n && b[j]>=0)
        ans+=b[j],j++;
    while(i<m && w[i]>0) {
        if (j>=i+1) {
            ans+=w[i];
        } else if (j<n && w[i]+b[j]>=0) {
            ans+=w[i]+b[j];
            j++;
        }
        i++;
    }
    cout << ans << "\n";
    
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
