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


bool possible(vector<int> &arr, ll time, int t) {
    ll numprods = 0;
    for(int i=0;i<arr.size();i++) {
        numprods+=time/arr[i];
        if (numprods>=t)
            return true;
    }
    return false;
}

void solve() {
	int n,t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    ll l=1,r=1e18l;
    while(l<r) {
        ll mid = l + (r-l)/2;
        if (!possible(arr, mid, t)) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    cout << l << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
