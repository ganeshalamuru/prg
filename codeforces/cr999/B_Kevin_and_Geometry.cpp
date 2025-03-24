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
    map<int,int>freq;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        freq[x]++;
    }
    int chosen = -1;
    for(auto &pp:freq) {
        if (pp.second>1) {
            chosen=pp.first;
        }
    }
    if (chosen==-1) {
        cout << -1 << "\n";
        return;
    }
    freq[chosen]-=2;
    int prev=-1;
    for(auto &&pp:freq) {
        if (pp.second==0)
            continue;
        if (pp.second>1) {
            cout << chosen << " " << chosen << " " << pp.first << " " << pp.first << "\n";
            return;
        }
        if (prev!=-1) {
            int base = pp.first-prev;
            if (2*chosen>base) {
                cout << chosen << " " << chosen << " " << pp.first << " " << prev << "\n";
                return;
            }
        }
        prev=pp.first;

    }
    cout << "-1\n";
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
