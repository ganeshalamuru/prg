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
	int a,b;
    cin >> a >> b;
    vector<pair<int,int>> aSideSols,bSideSols;
    for(int i=1;i<max(a,b);i++) {
        for(int j=1;j<max(a,b);j++) {
            if (i*i+j*j==a*a)
                aSideSols.push_back({i,j});
            if (i*i+j*j==b*b)
                bSideSols.push_back({i,j});
        }
    }
    for(int i=0;i<aSideSols.size();i++) {
        int x1 = aSideSols[i].F;
        int y1 = aSideSols[i].S; 
        for(int j=0;j<bSideSols.size();j++) {
            int x2 = bSideSols[j].F;
            int y2 = bSideSols[j].S;
            if ((x1+x2)*(x1+x2)+(y1-y2)*(y1-y2) == a*a + b*b && y1!=y2) {
                cout << "YES\n";
                cout << "0 0\n";
                cout << -x1 << " " << y1 << "\n";
                cout << x2 << " " << y2 << "\n";
                return;
            }
            if ((x2+y2)*(x2+y2)+(y1-x2)*(y1-x2) == a*a + b*b && y1!=x2) {
                cout << "YES\n";
                cout << "0 0\n";
                cout << -x1 << " " << y1 << "\n";
                cout << y2 << " " << x2 << "\n";
                return;
            }
            if ((y1+x2)*(y1+x2)+(x1-y2)*(x1-y2) == a*a + b*b && x1!=y2) {
                cout << "YES\n";
                cout << "0 0\n";
                cout << -y1 << " " << x1 << "\n";
                cout << x2 << " " << y2 << "\n";
                return;
            }
            if ((y1+y2)*(y1+y2)+(x1-x2)*(x1-x2) == a*a + b*b && x1!=x2) {
                cout << "YES\n";
                cout << "0 0\n";
                cout << -y1 << " " << x1 << "\n";
                cout << y2 << " " << x2 << "\n";
                return;
            }
        }
    }

    cout << "NO\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
