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
    string s;
    cin >> s;
    int j=0;
    ll ans =0;
    while(j < n) {
        int bit = s[j] -'0';
        ll cnt = 0;
        while(j < n && bit==s[j]-'0') cnt++,j++;
        cnt-=2;
        ans += ((cnt)*(cnt+1))/2;
    }
    j=0;
    while(j<n) {
        int bit = s[j]-'0';
        ll len = 0;
        while(j<n && bit==s[j]-'0') len++, bit^=1, j++;
        if (len < 3)
            continue;
        ll tmp = len / 2;
        if (len%2 == 0) {
            tmp--;
            ans += (tmp*(tmp+1));
        } else 
            ans += (tmp*tmp);
    }
    cout << ans << "\n";
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
