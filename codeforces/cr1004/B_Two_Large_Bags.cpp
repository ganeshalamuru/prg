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
    vector<int> arr(n+2,0);
    for(int i=0,num;i<n;i++)
        cin >> num,arr[num]++;
    for(int i=1;i<=n;i++) {
        if (arr[i]==0)
            continue;
        if (arr[i]==1) {
            cout << "No\n";
            return;
        }
        if (arr[i]>=2) {
            arr[i+1]+=arr[i]-2;
            arr[i]=2;
        }
    }
    for(int i=1;i<=n+1;i++) {
        if (arr[i]%2==1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    
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
