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
	int n;
    cin >> n;
    vector<int> b(n),a(n,-1);
    for(int i=1;i<=n-2;i++)
        cin >> b[i];
    int num =1;
    for(int i=1;i<=n-2;i++) {
        if (b[i]==0)
            continue;
        int minn = max(a[i-1],max(a[i],a[i+1]));
        if (minn==-1)
            num++;
        else
            num=minn;
        a[i-1]=a[i]=a[i+1]=num;
    }
    for(int i=1;i<=n-2;i++) {
        if (b[i]==1)
            continue;
        if (a[i]==a[i-1] && a[i]==a[i+1] && a[i]!=-1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
