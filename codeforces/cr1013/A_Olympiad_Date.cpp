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
    vector<int> arr(n),freq(10,0);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> rfreq(10,0);
    rfreq[0]=3,rfreq[1]=1,rfreq[2]=2,rfreq[3]=1,rfreq[5]=1;
    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
        bool pos = true;
        for(int j=0;j<10;j++) {
            if (rfreq[j]>freq[j]) {
                pos = false;
                break;
            }
        }
        if (pos) {
            cout << i+1 << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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
