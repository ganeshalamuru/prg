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
    map<int,int> rowb,roww;
    set<int> rows;
    for(int i=0;i<m;i++) {
        int x,y;
        string s;
        cin >> x >> y >> s;
        x--,y--;
        rows.insert(x);
        if (s[0]=='B') {
            rowb[x]=max(rowb[x],y);
        } else {
            if (roww.find(x)==roww.end())
                roww[x]=y;
            else
                roww[x] = min(roww[x], y);
        }
    }
    int maxbind = INT_MAX;
    for(auto &row:rows) {
        if (rowb.find(row)!=rowb.end() && roww.find(row)!=roww.end()) {
            if (rowb[row]>roww[row]) {
                cout << "No\n";
                return;
            }
        }
        if (rowb.find(row)!=rowb.end() && rowb[row]>maxbind) {
            cout << "No\n";
            return;
        }
        if (roww.find(row)!=roww.end())
            maxbind=min(maxbind, roww[row]-1);
    }
    cout << "Yes\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
