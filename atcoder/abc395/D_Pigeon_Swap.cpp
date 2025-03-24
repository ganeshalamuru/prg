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
	int n,q;
    cin >> n >> q;
    vector<int> oldd(n+1,0),neww(n+1,0);
    vector<int> pegion(n+1,0);
    for(int i=1;i<=n;i++)
        oldd[i]=i,neww[i]=i,pegion[i]=i;
    while (q--) {
        int type,a,b;
        cin >> type;
        if (type==1) {
            cin >> a >> b;
            pegion[a]=neww[b];
        } else if (type==2) {
            cin >> a >> b;
            int oldda = neww[a],olddb=neww[b];
            swap(oldd[oldda],oldd[olddb]);
            swap(neww[a],neww[b]);
        } else {
            cin >> a;
            cout << oldd[pegion[a]] << "\n";
        }
    }
    
    

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
