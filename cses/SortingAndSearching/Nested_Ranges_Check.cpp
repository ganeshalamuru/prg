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

// max end of open segments
// 1 2 3 4 8 10
// 1st cast
//              mine ------
//    does it have     --
// 2n case
//              mine -------
// does it have  ---------------
void solve() {
	int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }
    sort(arr.begin(), arr.end(), [](const vector<int>&a,const vector<int>&b) {
        if (a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    });
    vector<vector<int>> ans (2,vector<int>(n,0));
    set<pii> ends;
    for(int i=0;i<n;i++) {
        while(!ends.empty() && ends.begin()->F<arr[i][0])
            ends.erase(ends.begin());
        if (!ends.empty() && arr[i][1]<=ends.rbegin()->F)
            ans[1][arr[i][2]]=ends.size();
        ends.insert({arr[i][1], arr[i][2]});
    }
    ends.clear();
    for(int i=0;i<n;i++) {
        while(!ends.empty() && ends.begin()->F<arr[i][0]) {
            ends.erase(ends.begin());
        }
        while(!ends.empty() && arr[i][1]<=ends.rbegin()->F) {
            ans[0][ends.rbegin()->S]=1;
            ends.erase(*ends.rbegin());
        }
        ends.insert({arr[i][1], arr[i][2]});
    }
    for(int j=0;j<2;j++) {
        for(int i=0;i<n;i++)
            cout << ans[j][i] << " ";
        cout << "\n";
    }

}




signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
