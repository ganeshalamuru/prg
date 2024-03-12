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


ld distsq(ld x1, ld y1, ld x2, ld y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

bool valid(ld w, ll px, ll py, ll ax, ll ay, ll bx, ll by) {
    // both home and work inside first circle
    ld radiussq = w*w;
    if (distsq(0,0,ax,ay) - radiussq < 1e-7 && distsq(px,py,ax,ay)-radiussq < 1e-7) {
        return true;
    }
    // both home and work inside second circle
    if (distsq(0,0,bx,by) - radiussq < 1e-7 && distsq(px,py,bx,by)-radiussq < 1e-7) {
        return true;
    }
    if (distsq(0,0,ax,ay) - radiussq < 1e-7 && distsq(px,py,bx,by) - radiussq < 1e-7 && distsq(ax,ay,bx,by) - 4*radiussq < 1e-7) {
        return true;
    }
    if (distsq(0,0,bx,by) - radiussq < 1e-7 && distsq(px,py,ax,ay) - radiussq < 1e-7 && distsq(ax,ay,bx,by) - 4*radiussq < 1e-7) {
        return true;
    }
    return false;
}

void solve(){
	ll px,py,ax,ay,bx,by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    ld l = 0, r = 1e6;
    while(r-l>1e-7) {
        ld mid = l+(r-l)/2;
        if (valid(mid, px,py,ax,ay,bx,by)) {
            r=mid;
        } else {
            l=mid;
        }
    }
    cout << setprecision(7) << fixed << l << "\n";
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
