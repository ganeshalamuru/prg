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
    map<int,pii> freq;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        if (freq.find(x)==freq.end()) {
            freq[x] = {1,i};
        } else {
            freq[x] = {freq[x].F+1,i};
        }
    }
    int maxnum = -1;
    for(auto &pp:freq) {
        if (pp.second.first>1)
            continue;
        maxnum= max(maxnum, pp.first);
    }
    if (maxnum!=-1)
        cout << freq[maxnum].second+1<< "\n";
    else
        cout << -1 << "\n";
}




signed main() {
    fast;
    int t = 1;
    
    while(t--){
    	solve();
    }
    return 0;
}
