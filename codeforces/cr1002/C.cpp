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
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    vector<int> freqs;
    for(int i=0;i<n;i++) {
        int consec1s = 0;
        for(int j=n-1;j>=0;j--) {
            if (a[i][j]==1) {
                consec1s++;
            } else {
                freqs.push_back(consec1s);
                break;
            }
        }
        if (consec1s==n)
            freqs.push_back(consec1s);
    }
    sort(freqs.begin(), freqs.end());
    int req = 0, j=0;
    while(j<n) {
        if (req<=freqs[j]) {
            req++,j++;
            continue;
        } else {
            j++;
        }
    }
    cout << req << "\n"; 
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
