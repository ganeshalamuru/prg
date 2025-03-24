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


long double getDegrees(long double radians)  {
    return radians * 180.0 / numbers::pi;
}

long double getArcTan(int x, int y) {
    long double rad = atan2l(y,x);
    long double deg = getDegrees(rad);
    if (deg < 0)
        return 360.0 + deg;
    return deg;
}

void solve() {
	int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(3));
    vector<long double> arctanvalues(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2]=i;
        arctanvalues[i] = getArcTan(arr[i][0],arr[i][1]);
    }
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    sort(arr.begin(),arr.end(), [&arctanvalues](const auto &a, const auto &b) {return arctanvalues[a[2]] < arctanvalues[b[2]];});
    long double ans = 360.0;
    for(int i=1;i<n;i++) {
        ans = min(ans, 360.0 - getArcTan(arr[i][0],arr[i][1]) + getArcTan(arr[i-1][0],arr[i-1][1]));
    }
    ans = min(ans, getArcTan(arr[n-1][0],arr[n-1][1]) - getArcTan(arr[0][0],arr[0][1]));
    cout <<  fixed << setprecision(7) << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
