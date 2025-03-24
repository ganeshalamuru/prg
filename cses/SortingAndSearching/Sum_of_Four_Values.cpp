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
        cin >> arr[i][0],arr[i][1]=i;
    sort(arr.begin(), arr.end());
    map<int, pii> mp;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if (mp.find({arr[j][0]+arr[i][0]})==mp.end())
                mp[arr[j][0]+arr[i][0]]={arr[j][1],arr[i][1]};
        }
    }
    for(int i=n-1;i>=3;i--) {
        for(int j=i-1;j>=2;j--) {
            int req = x - arr[i][0] - arr[j][0];
            if (mp.find(req) != mp.end()) {
                pii pp = mp[req];
                if (arr[j][1]!=pp.F && arr[j][1]!=pp.S && arr[i][1]!=pp.F && arr[i][1]!=pp.S) {
                    cout << arr[i][1]+1 << " " << arr[j][1]+1 << " ";
                    cout << mp[req].F+1 << " " << mp[req].S+1 << "\n";
                    return;
                }
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