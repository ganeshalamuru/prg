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
 
 
 
int f(int n, int j) {
    if (n==1)
        return 1;
    if (j%2==0)
        return j/2;
    if (n%2==0) {
        return n/2 + f(n/2, (j+1)/2);
    } else if (j==n) {
        return (n-1)/2 + f((n+1)/2, 1);
    } else 
        return (n-1)/2 + f((n+1)/2, 1 + (j+1)/2);
}
 
 
void solve() {
	int n;
    cin >> n;
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++) {
        ans[f(n,i)]=i;
    }
    for(int i=1;i<=n;i++)
        cout << ans[i] << " ";
}
 
 
 
 
signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}