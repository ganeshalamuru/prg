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
    vector<int>arr(n);
    vector<int> odd;
    int evencnt = 0;
    ll evensum = 0;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        if (x%2==1) {
            odd.push_back(x);
        } else {
            evencnt++;
            evensum+=x;
        }
        arr[i]=x;
    }
    if (evencnt==0 || evencnt==n) {
        cout << *max_element(arr.begin(), arr.end()) << "\n";
        return;
    }
    sort(odd.rbegin(),odd.rend());
    ll ans = evensum+(*odd.begin());
    // got lucky here, eventcnt is irrelevant lol
    for(int j=1,cnt = 0;j<odd.size() && cnt<evencnt;j++) {
        ans+=odd[j]-1;
    }
    cout << ans << "\n";
    
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
