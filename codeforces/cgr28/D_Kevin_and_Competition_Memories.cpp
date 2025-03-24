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
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];
    int kevinrating = a[0];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> numpeephardsolves(m,0);
    int i=n-1,j=m-1;
    while(j>=0 && b[j]>kevinrating) {
        while(i>=0 && a[i]>kevinrating && a[i]>=b[j])
            i--;
        numpeephardsolves[j]=n-i-1;
        j--;
    }
    sort(numpeephardsolves.begin(), numpeephardsolves.end());
    for(int z=1;z<=m;z++) {
        ll ans = 0;
        for(int s=0;s+z-1<m;s+=z) {
            ans += numpeephardsolves[s+z-1]+1;   
        }
        cout << ans << " ";
    }
    cout << "\n";
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
