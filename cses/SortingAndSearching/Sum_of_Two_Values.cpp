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
	int n,x;
    cin >> n >> x;
    vector<vector<int>>a(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin >> a[i][0],a[i][1]=i;
    sort(a.begin(), a.end());
    int i=0,j=n-1;
    while(i<j) {
        if(a[i][0]+a[j][0]==x) {
            cout << a[i][1]+1 << " " << a[j][1]+1 << "\n";
            return;
        } else if (a[i][0]+a[j][0]>x) {
            j--;
        } else {
            i++;
        }
    }
    cout << "IMPOSSIBLE\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
