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
    vector<vector<int>> points(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin >> points[i][0] >> points[i][1];
    }
    int maxareatwice = -1; 
    for(int i=0;i<n;i++) {
        int x1 = points[i][0], y1=points[i][1];
        for(int j=i+1;j<n;j++) {
            if (j==i)
                continue;
            int x2 = points[j][0], y2 = points[j][1];
            // eq of line ax + by + c = 0
            int a = (y2-y1), b = -(x2-x1), c = -x2*a-y2*b;
            int maxval = INT_MIN, maxabsnegval = INT_MIN;
            for(int z=0;z<n;z++) {
                int x = points[z][0], y = points[z][1];
                if (z==j || z==i)
                    continue;
                int val = a*x + b*y + c;
                if (val>0)
                    maxval =max(maxval, val);
                else
                    maxabsnegval=max(maxabsnegval, -val);
            }
            if (maxval==INT_MIN || maxabsnegval==INT_MIN)
                continue;
            maxareatwice = max(maxareatwice, maxval+maxabsnegval);
        }
    }
    cout << fixed << setprecision(10) <<1.0l*maxareatwice/2 << "\n";
    
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
