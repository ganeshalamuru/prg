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
	int x;
    cin >> x;
    int l=0, r=49;
    while(l<r) {
        int mid = l + (r-l)/2;
        int t1floor = mid>>1;
        int t1ciel = mid - t1floor;
        int totalOnes = 0;
        if (x%4==0)
            totalOnes += 4*(2*(t1ciel*t1floor) + t1ciel);
        else
            totalOnes += 4*(t1floor*t1floor + t1ciel*t1ciel + t1floor) + 1;
        if (x > totalOnes || (x%4==2 && 4*(t1ciel)<2) || (x%4==3 && 4*t1floor<2))
            l = mid + 1;
        else  
            r = mid;
    }
    cout << 2*l+1 << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
