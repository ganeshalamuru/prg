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
	int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> arr[i][j];
    for(int i=0;i<n;i++)
        sort(arr[i].begin(), arr[i].end());
    vector<pair<int,int>> order(n);
    for(int i=0;i<n;i++)
        order[i] = {arr[i][0], i};
    sort(order.begin(), order.end());
    vector<int> inds(n,0);
    int topcard = -1;
    for(int i=0;i<m;i++) {
        for(int z=0;z<n;z++) {
            if (arr[order[z].S][i] < topcard) {
                cout << -1 << "\n";
                return;
            }
            topcard=arr[order[z].S][i];
        }
    }
    for(int i=0;i<n;i++) {
        cout << order[i].S+1 << " ";
    }
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
