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
    vector<vector<int>> arr(2*n-1,vector<int>(3));
    ll suma = 0, sumo = 0;
    for(int i=0;i<arr.size();i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2]=i;
        suma+=arr[i][0], sumo+=arr[i][1];
    }
    sort(arr.rbegin(), arr.rend());
    ll sumorangeevenind = 0;
    for(int i=0;i<arr.size();i+=2) {
        sumorangeevenind+=arr[i][1];
    }
    cout << "YES\n";
    if (2*sumorangeevenind >= sumo) {
        for(int i=0;i<arr.size();i+=2)
            cout << arr[i][2]+1 << " ";
        cout << "\n";
    } else {
        cout << arr[0][2]+1 << "\n";
        for(int i=1;i<arr.size();i+=2)
            cout << arr[i][2]+1 << " ";
        cout << "\n";
    }
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
