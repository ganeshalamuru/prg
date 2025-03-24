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
	int n,x;
    cin >> n >> x;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin >> arr[i][0], arr[i][1]=i;
    sort(arr.begin(), arr.end());
    for(int z=n-1;z>=2;z--) {
        int req =x-arr[z][0];
        int i=0,j=z-1;
        while(i<j) {
            if (arr[i][0]+arr[j][0]==req) {
                cout << arr[z][1]+1 << " " << arr[i][1]+1 << " " << arr[j][1]+1 << "\n";
                return;
            } else if (arr[i][0]+arr[j][0]<req) {
                i++;
            } else {
                j--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
