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
    vector<pii> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i].F >> arr[i].S;
    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {if(a.S==b.S) return a.F<b.F;
         else return a.S<b.S;});
    int ans = 1,i=1,lastmovie = 0;
    while(i<n) {
        if (arr[lastmovie].S<=arr[i].F)
            ans++,lastmovie=i;
        i++;
    }
    cout << ans << "\n";

}




signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
