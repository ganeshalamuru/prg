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
	int n,k,q;
    cin >> n >> k >> q;
    vector<vector<int>> arr(k,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cin >> arr[j][i];
    vector<vector<int>> orbits(k,vector<int>(n));
    for(int j=0;j<k;j++)
        orbits[j][0] = arr[j][0];
    for(int i=1;i<n;i++)
        for(int j=0;j<k;j++)
            orbits[j][i]=orbits[j][i-1]|arr[j][i]; 
    while(q--) {
        int m;
        cin >> m;
        vector<vector<int>> qq(m,vector<int>(2));
        vector<char> op(m);
        for(int i=0;i<m;i++)
            cin >> qq[i][0] >> op[i] >> qq[i][1];
        int l=0,r=n-1;
        for(int i=0;i<m;i++) {
            int reg = qq[i][0]-1, val = qq[i][1];
            auto startitr = orbits[reg].begin(), enditr = orbits[reg].end();
            if (op[i]=='>') {
                auto itr = upper_bound(startitr, enditr, val);
                l = max(l, (int)(itr-startitr));
            } else {
                auto itr = lower_bound(startitr, enditr, val);
                if (itr==startitr)
                    r = -1;
                else if (itr != enditr)
                    itr--,r = min(r, (int)(itr-startitr));
            }
        }
        if (l<=r)
            cout << l+1 << "\n";
        else
            cout << -1 << "\n";
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
