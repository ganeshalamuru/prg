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




void solve(){
	int n;
    cin >> n;
    if (n<6) {
        cout << -1 << "\n";
    } else {
        vector<string> edges{"1 2\n","1 3\n","1 4\n", "2 5\n", "2 6\n"};
        for(auto edge:edges)
            cout << edge;
        for(int i=7;i<=n;i++)
            cout << "1 " << i << "\n";
    }
    for(int i=1;i<n;i++)
        cout << i << " "<< i+1 << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
