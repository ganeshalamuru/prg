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
    int refx, refy;
    cin >> refx >> refy;
    refx--,refy--;
	vector<int> x(2),y(2);
    for (int i =0;i<2;i++) {
        cin >> x[i]>> y[i];
        x[i]--,y[i]--;
        x[i]-=refx,y[i]-=refy;
    }
    int commoncells = 1;
    if ((x[0]>=0 && x[1]>=0) || (x[0]<=0 && x[1]<=0))
        commoncells += min(abs(x[0]),abs(x[1]));
    
    if ((y[0]>=0 && y[1]>=0) || (y[0]<=0 && y[1]<=0))
        commoncells += min(abs(y[0]),abs(y[1]));
    
    cout << commoncells << "\n";

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
