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
    vector<int> a(n);
    int indnum = n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1)
            indnum=i;
    }
    vector<int> dpmax(n,INT_MIN),dpmin(n,INT_MAX);
    dpmax[0] = a[0], dpmin[0] = a[0];
    for(int i=1;i<=indnum && i<n;i++) {
        dpmax[i] = max(a[i], a[i]+dpmax[i-1]);
        dpmin[i] = min(a[i], a[i]+dpmin[i-1]);
    }
    if (indnum+1<n) {
        dpmax[indnum+1]=a[indnum+1];
        dpmin[indnum+1]=a[indnum+1];
        for(int i=indnum+2;i<n;i++) {
            dpmax[i] = max(a[i], a[i]+dpmax[i-1]);
            dpmin[i] = min(a[i], a[i]+dpmin[i-1]);
        }
    }
        
    vector<pair<int,int>> mmintervals;
    for(int i=0;i<=indnum && i<n;i++) {
        mmintervals.push_back({dpmin[i], dpmax[i]});
    }
    pair<int,int> previnterval = mmintervals.back();
    int sum = 0;
    for(int i=indnum+1;i<n;i++) {
        sum+=a[i];
        mmintervals.push_back({dpmin[i], dpmax[i]});
        mmintervals.push_back({previnterval.F+sum, previnterval.S+sum});
    }
    mmintervals.push_back({0,0});
    sort(mmintervals.begin(), mmintervals.end());
    vector<pair<int,int>> merged;
    merged.push_back(mmintervals[0]);
    for(int i=1;i<mmintervals.size();i++) {
        if (mmintervals[i].F > merged.back().S)
            merged.push_back(mmintervals[i]);
        else
            merged.back().S = max(merged.back().S, mmintervals[i].S);
    }
    vector<int> ans;
    for(int i=0;i<merged.size();i++) {
        for(int j=merged[i].F;j<=merged[i].S;j++)
            ans.emplace_back(j);
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " "; 
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
