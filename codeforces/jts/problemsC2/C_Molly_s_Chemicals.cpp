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
	int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<ll> psum(n);
    psum[0] = arr[0];
    for(int i=1;i<n;i++)
        psum[i] = arr[i] + psum[i-1];
    map<ll,ll> mp{{0,1}};
    ll ans = 0;
    for(int i=0;i<n;i++) {
        if (k==1) {
            if (mp.find(psum[i]-1) != mp.end())
                ans+=mp[psum[i]-1];
        } else if (k==-1) {
            if (mp.find(psum[i]-1) != mp.end())
                ans+=mp[psum[i]-1];
            if (mp.find(psum[i]+1) != mp.end())
                ans+=mp[psum[i]+1];
        } else {
            ll temp = 1;
            while(abs(temp)<1e15) {
                if (mp.find(psum[i]-temp) != mp.end())
                    ans+=mp[psum[i]-temp];
                temp*=k;
            }
        }
        mp[psum[i]]++;
    }
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
