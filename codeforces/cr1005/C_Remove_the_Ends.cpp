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
    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<ll>a;
    int j=0;
    while(j<n) {
        ll sum = 0;
        if (arr[j]<0) {
            while(j<n && arr[j]<0)
                sum+=arr[j],j++;
        } else {
            while(j<n && arr[j]>0)
                sum+=arr[j],j++;
        }
        a.push_back(sum);
    }
    ll ans = LLONG_MIN;
    int m = a.size();
    vector<ll> ppsum(m,0),nssum(m,0);
    if (a[0]>0)
        ppsum[0]=a[0];
    if (a[m-1]<0)
        nssum[m-1]=abs(a[m-1]);
    for(int i=1;i<m;i++) {
        if (a[i]<0)
            ppsum[i]=ppsum[i-1];
        else
            ppsum[i]=ppsum[i-1]+a[i];
    }
    for(int j=m-2;j>=0;j--) {
        if (a[j]>0)
        nssum[j]=nssum[j+1];
        else
        nssum[j]=nssum[j+1]+abs(a[j]);
    }
    ans = max(ppsum[m-1], nssum[0]);
    for(int i=0;i<m-1;i++) {
        if (a[i]>0 && a[i+1]<0)
            ans=max(ans, ppsum[i]+nssum[i+1]);
    }
    cout << ans << "\n";
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
