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
	vector<int> freq(14,0);
    for(int i=0,x;i<7;i++)
        cin >> x,freq[x]++;
    for(int i=1;i<14;i++) {
        for(int j=i+1;j<14;j++) {
            if ((freq[i]>=3 && freq[j]>=2) || freq[i]>=2 && freq[j]>=3 ) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
