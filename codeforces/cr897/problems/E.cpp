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




void solve(){
	int n,k;
    cin >> n >> k;
    int q = n/k;
    int r = n%k;
    int ans = 0;
    for(int a,i=1,j=0;j<q;i+=k,j++) {
        cout << "? " << i << "\n" << flush;
        cin >> a;
        if (a==-1) {
            return;
        }
        ans^=a;
    }
    if (r!=0) {
        int temp = 0;
        for(int a,i=1;i<=r;i++) {
            cout << "? " << (q-1)*k+1+i << "\n" << flush;
            cin >> a;
            if (a==-1) {
                return;
            }
            temp^=a; 
        }
        ans^=temp;
    }
    cout << "! " << ans << "\n" << flush;

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
