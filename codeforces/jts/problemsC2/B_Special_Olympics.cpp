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

bool greatereq(long double a, long double b) {
    return abs(a-b)<1e-6 || a > b;
}
bool lessereq(long double a, long double b) {
    return abs(a-b)<1e-6 || a < b;
}

int doesntintersectwithcircle(int x, int y, int r, int x2, int y2, int r2) {
    long double dis = hypotl(x-x2,y-y2);
    if (greatereq(dis, r+r2)) {
        return 1;
    }
    if (lessereq(dis+min(r,r2), max(r,r2)))
        return min(r,r2)==r2?1:0;
    return -1;
}

bool doesntintersectwithring(int x,int y,int r,int x2,int y2,int r2,int R2) {
    int t1 = doesntintersectwithcircle(x,y,r,x2,y2,r2);
    int t2 = doesntintersectwithcircle(x,y,r,x2,y2,R2);
    if (t1 == -1 || t2 == -1 || (t1^t2)==1 )
        return false;
    return true;
}


void solve() {
	int x1,y1,r1,R1;
    int x2,y2,r2,R2;
    cin >> x1 >> y1 >> r1 >> R1;
    cin >> x2 >> y2 >> r2 >> R2;
    int ans = 0;
    ans += doesntintersectwithring(x1,y1,r1,x2,y2,r2,R2);
    ans += doesntintersectwithring(x1,y1,R1,x2,y2,r2,R2);
    ans += doesntintersectwithring(x2,y2,r2,x1,y1,r1,R1);
    ans += doesntintersectwithring(x2,y2,R2,x1,y1,r1,R1);
    cout << ans << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
