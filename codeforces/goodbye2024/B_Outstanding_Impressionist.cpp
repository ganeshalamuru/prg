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
    vector<pair<int,int>> arr(n);
    int maxval = INT_MIN;
    for(int i=0;i<n;i++) {
        cin >> arr[i].F >> arr[i].S;
        maxval = max(maxval, arr[i].S);
    }
    vector<int> scnt(maxval+1,0);
    for(int i=0;i<n;i++) {
        if (arr[i].F == arr[i].S)
            scnt[arr[i].F]++;
    }
    vector<int> scntpsum(maxval+1,0);
    for(int i=1;i<maxval+1;i++)
        scntpsum[i] = scntpsum[i-1] + min(1,scnt[i]);
    for(int i=0;i<n;i++) {
        if (arr[i].F == arr[i].S) {
            if (scnt[arr[i].F]>1) {
                cout << "0";
            } else {
                cout << "1";
            }
        } else if (scntpsum[arr[i].S]-scntpsum[arr[i].F-1] == (arr[i].S-arr[i].F+1))
            cout << "0";
        else
            cout << "1";
    }
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
