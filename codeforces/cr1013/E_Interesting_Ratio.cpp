#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 1e7l+1, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}



vector<int> prime(N,1);

void sieve() {
    prime[0]=prime[1]=0;
    for(int i=2;1ll*i*i<N;i++) {
        if (prime[i]==1) {
            for(int j=i*i;j<N;j+=i) {
                prime[j]=0;
            }
        }
    }
}

void solve() {
	int n;
    cin >> n;
    ll ans = 0;
    for(int i=2;i<=n;i++) {
        ans+=prime[i]*(n/i);
    }
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    sieve();
    while(t--){
    	solve();
    }
    return 0;
}
