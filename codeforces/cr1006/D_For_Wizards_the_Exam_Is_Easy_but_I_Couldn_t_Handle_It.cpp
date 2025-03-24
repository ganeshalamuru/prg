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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int l=0,r=0,maxinvred = 0;
    for(int i=0;i<n;i++) {
        int num = arr[i];
        int les=0,gret=0;
        for(int j=i;j<n;j++) {
            if (arr[j]>num)
                gret++;
            else if (arr[j]<num)
                les++;
            if (les-gret>maxinvred)
                maxinvred=les-gret,l=i,r=j;
        }
    }
    cout << l+1<< " " << r+1 << "\n";
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
