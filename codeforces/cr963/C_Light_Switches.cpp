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
	int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &num:arr)
        cin >> num;
    sort(arr.rbegin(), arr.rend());
    int leftr = arr[0], rightr = arr[0]+k-1;
    set<int> ss;
    int maxmod2k = arr[0]%(2*k);
    ss.insert(maxmod2k);
    for(int i=1;i<n;i++) {
        int rem = arr[i]%(2*k);
        if (ss.find(rem+k) != ss.end() || ss.find(rem-k) != ss.end()) {
            cout << -1 << "\n";
            return;
        }
        if (maxmod2k > rem) {
            if (maxmod2k - rem > k) {
                leftr = max(leftr, arr[0] - maxmod2k + rem + 2*k);
                rightr = min(rightr, arr[0] - maxmod2k + rem + 2*k + k - 1);
            } else {
                leftr = max(leftr, arr[0] - maxmod2k + rem);
                rightr = min(rightr, arr[0] - maxmod2k + rem + k - 1);
            }
        } else {
            if (rem - maxmod2k > k) {
                leftr = max(leftr, arr[0] - maxmod2k + rem - 2*k);
                rightr = min(rightr, arr[0] - maxmod2k + rem - 2*k + k - 1);
            } else {
                leftr = max(leftr, arr[0] - maxmod2k + rem);
                rightr = min(rightr, arr[0] - maxmod2k + rem + k - 1);
            }
        }
        ss.insert(arr[i]%(2*k));
    }
    if (leftr > rightr) {
        cout << -1 << "\n";
    } else 
        cout << leftr << "\n";
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
