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
	int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int j=0;j<m;j++)
        cin >> b[j];
    int xora=0, orofall=0;
    for(int i=0;i<n;i++)
        xora^=a[i];
    for(int j=0;j<m;j++)
        orofall|=b[j];
    if (n%2 == 1) {
        cout << xora << " " << (xora|orofall) << "\n";
    } else {
        cout << (xora&(~orofall))<< " " << xora << "\n";
    }
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
