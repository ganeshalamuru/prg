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



bool valid(int x,int y,int z) {
    set<int> s{x,y,z};
    if (s.size()==3)
        if (x>0 && y>0 && z>0)
            if (x%3!=0 && y%3!=0 && z%3 != 0)
                return true;
    return false;
}

void solve(){
	int n;
    cin >> n;
    vector<pair<int,int>> pairs{{1,2},{1,4},{2,5}};
    for(auto pp:pairs) {
        int rem = n-pp.F-pp.S;
        if (valid(pp.F, pp.S, rem)) {
            cout << "YES\n";
            cout << pp.F << " " << pp.S << " " << rem << "\n";
            return;
        }
    }
    cout << "NO\n";
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
