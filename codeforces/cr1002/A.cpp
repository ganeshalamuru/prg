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
    vector<int>a(n),b(n);
    for(int &num:a)
        cin >> num;
    for(int &num:b)
        cin >> num;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    set<int> ss;
    ss.insert(a[0]+b[0]);
    ss.insert(a[n-1]+b[n-1]);
    if (ss.size()<2) {
        cout << "NO\n";
        return;
    }
    for(int i=1;i<n-1;i++) {
        for(int j=1;j<n-1;j++) {
            int t1 = a[i]+b[j];
            if (ss.find(t1) == ss.end()) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";

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
