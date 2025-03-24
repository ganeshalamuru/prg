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
    vector<pair<string, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].F;
        cin >> arr[i].S;
    }
    sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
        if (a.S == b.S) return a.F < b.F;
        return a.S < b.S;
    });
    vector<int> ans(n);
    map<int, string> mp;
    for(int i=0;i<n;i++) {
        if (arr[i].S>i) {
            cout << -1 << "\n";
            return;
        }
        int numtoadd = i+1-arr[i].S;
        ans[i] = numtoadd;
        int j = i-1;
        while(j>=0) {
            if (ans[j]>=numtoadd)
                ans[j]++;
            j--;
        }
    }
    for(int i=0;i<n;i++)
        cout << arr[i].F << " " << ans[i] << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
