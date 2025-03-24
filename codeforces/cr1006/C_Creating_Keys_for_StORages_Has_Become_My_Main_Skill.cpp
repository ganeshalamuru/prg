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
    cin >> n>>x;
    bitset<30> bs(x);
    int i=0;
    while(i<30 && bs[i]==1)
        i++;
    vector<int> ans;
    int num=0,totor = 0;
    for(int z=1;z<=n&&z<=(1<<i);z++) {
        ans.push_back(num);
        totor|=num;
        num++;
    }
    if (totor!=x && ans.size()>=n) {
            ans.pop_back();
    }
    while(ans.size()<n)
        ans.push_back(x);
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
