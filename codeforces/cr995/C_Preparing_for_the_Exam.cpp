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
	int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(m),q(k);
    vector<int> ind(n+1,-1);
    for(int i=0;i<m;i++)
        cin >> a[i], ind[a[i]]=i;
    for(int &num:q)
        cin >> num;
    vector<int> cananswerprf(m,0);
    for(int i=0;i<k;i++) {
        int indd = ind[q[i]];
        if (indd == -1) {
            cananswerprf[0]++;
        } else {
            cananswerprf[0]++;
            cananswerprf[indd]--;
            if (indd+1<m)
                cananswerprf[indd+1]++;
        }
    }
    int sum = 0;
    for(int i=0;i<m;i++) {
        sum+=cananswerprf[i];
        if (sum==n-1) {
            cout << "1";
        } else {
            cout << "0";
        }
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
