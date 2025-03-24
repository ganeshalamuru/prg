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
	ll n,k;
    cin >> n >> k;
    if (n-1<=60 && (1ll<<(n-1))<k) {
        cout << -1 << "\n";
        return;
    }
    vector<int> arr(n);
    int i=0,j=n-1,num=1,pow=n-1;
    while(num<=n) {
        if (pow-1>60) {
            arr[i]=num,i++;
        } else if (pow-1<=60 && k<=(1ll<<(pow-1))) {
            arr[i]=num,i++;
        } else {
            arr[j]=num,j--;
            k-=(1ll<<(pow-1));
        }
        num++;
        pow--;
    }
    for(int z=0;z<n;z++)
        cout << arr[z] << " ";
    cout << "\n";
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
