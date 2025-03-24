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



bool pos(vector<int>&arr, int k, ll maxsum) {
    int numsubarr = 0;
    int i=0,n=arr.size();
    while(i<n && arr[i]<=maxsum) {
        ll cursum = 0;
        while(i<n && cursum+arr[i]<=maxsum)
            cursum+=arr[i],i++;
        numsubarr++;
    }
    return numsubarr<=k && i==n;
}

void solve() {
	int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    ll l=1,r=1e15l;
    while(l<r) {
        ll mid = l + (r-l)/2;
        if (pos(arr, k, mid)) {
            r=mid;
        } else {
            l=mid+1;
        }
    }
    cout << l << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
