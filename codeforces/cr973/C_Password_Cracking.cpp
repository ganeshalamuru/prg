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
	int n,res;
    cin >> n;
    string t="";
    int dir = 1;
    while(t.size() < n) {
        if (dir == 1) {
            t.push_back('0');
            cout << "? " << t << endl,cout.flush();
            t.pop_back();
            cin >> res;
            if (res == 1) {
                t.push_back('0');
            } else {
                t.push_back('1');
                cout << "? " << t<< endl,cout.flush();
                t.pop_back();
                cin >> res;
                if (res == 1) {
                    t.push_back('1');
                } else {
                    dir=-1;
                    t='1'+t;
                }
            }
        } else {
            cout << "? " << '0'+t << endl,cout.flush();
            cin >> res;
            if (res == 1)
                t = '0'+t;
            else
                t = '1'+t;
        }
    }
    cout << "! " << t << endl,cout.flush();
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
