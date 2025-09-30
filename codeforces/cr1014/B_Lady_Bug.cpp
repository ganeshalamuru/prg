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
    vector<string> arr(2);
    cin >> arr[0] >> arr[1];
    vector<vector<int>> oddevencnt(2,{0,0});
    for(int j=0;j<2;j++) {
        for(int i=0;i<n;i++) {
            oddevencnt[j][i%2]+=arr[j][i]-'0';
        }
    }
    if (oddevencnt[1][0]+oddevencnt[0][1]>(n/2+n%2) || oddevencnt[1][1]+oddevencnt[0][0]>n/2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
     
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
