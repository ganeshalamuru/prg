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
	int n,d;
    cin >> n >> d;
    vector<int> ans{1};
    if (d%3==0 || n>=3)
        ans.push_back(3);
    if (d%10==5)
        ans.push_back(5);
    if (n>=3 || (d*4*8)%7==0)
        ans.push_back(7);
    if (n>=6)
        ans.push_back(9);
    else {
        int sum = d;
        for(int i=1;i<=n;i++)
            sum*=i;
        if (sum%9==0)
            ans.push_back(9);
    }
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    cout << "\n";
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
