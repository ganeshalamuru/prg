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


int mask(int num) {
    int m = 0,b10 = 1;
    while(num > 0) {
        int digit = num%10;
        if (digit == 4 || digit == 7) {
            m=b10*(digit)+m;
            b10*=10;
        }
        num/=10;
    }
    return m;
}

void solve() {
	int a,b;
    cin >> a >> b;
    int curnum = a+1;
    while(true) {
        if (mask(curnum) == b)
            break;
        curnum++;
    }
    cout << curnum << "\n";                                                                                                               
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
