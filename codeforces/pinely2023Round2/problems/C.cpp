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
    vector<int> arr(n+1),pres(n+1,0);
    for(int i=0;i<n;i++)
        cin >> arr[i], pres[arr[i]]=1;
    int mex = -1;
    for(int i=0;i<=n;i++) {
        if (pres[i] == 0) {
            mex = i;
            break;
        }
    }    
    arr[n] = mex;
    k=k%(n+1);
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";
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
