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
    vector<int> arr(n),freq(n+1,0);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int i=0,j=0,maxlen = 0, ai=-1,aj=-1;
    while(j<n) {
        if (freq[arr[j]]==1) {
            if (maxlen < j-i+1)
                maxlen=j-i+1,ai=i,aj=j;
            j++;
        } else {
            j++;
            i=j;
        }
    }
    if (maxlen==0)
        cout << 0 << "\n";
    else
        cout << ai+1 << " " << aj+1 << "\n";
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
