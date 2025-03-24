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
	int n,l,r;
    cin >> n >> l >> r;
    l--,r--;
    vector<int> arr(n);
    vector<int> segment,left,right;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if (i<l)
            left.push_back(arr[i]);
        else if (l<=i && i<=r)
            segment.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    int segsize = segment.size();
    vector<int> leftcombined=left, rightcombined=right;
    for(int i=0;i<segsize;i++)
        leftcombined.push_back(segment[i]), rightcombined.push_back(segment[i]);
    sort(leftcombined.begin(), leftcombined.end());
    sort(rightcombined.begin(), rightcombined.end());
    ll leftminsum =0, rightminsum = 0;
    for(int i=0;i<segsize;i++) {
        leftminsum+=leftcombined[i];
        rightminsum+=rightcombined[i];
    }
    cout << min(leftminsum, rightminsum) << "\n";

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
