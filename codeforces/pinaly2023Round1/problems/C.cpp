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



void solve(){
	int n;
    cin >> n;
    vector<string> brd(n);
    for(auto& str:brd)
        cin >> str;
    vector<vector<int>> edges(n);
    vector<set<int>> sets(n);
    for(int i=0;i<n;i++)
        sets[i].insert(i);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (brd[i][j] == '1') {
                sets[j].insert(i);
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout << sets[i].size() << " ";
        for(int num:sets[i])
            cout << num+1 << " ";
        cout << "\n";
    }
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
