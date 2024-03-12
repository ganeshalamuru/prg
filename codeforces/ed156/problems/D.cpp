#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 998244353, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


int minv (ll a){
    a = a%mod;
	return powe(a, mod-2);
}
int mmul (ll a, ll b){
    a = a%mod, b = b%mod;
	return (1ll * a * b)%mod;
}
int mdiv (ll a, ll b){
	return mmul(a, minv(b));
}


void solve(){
	int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ans = 1;
    set<int> indices;
    for(int i=0;i<s.size();i++)
        if (s[i]=='?')
            indices.insert(i), ans = mmul(ans, max(1,i));
    if (indices.find(0) == indices.end())
        cout << ans << "\n";
    else
        cout << 0 << "\n";
    while(m--) {
        int ind;
        string qq;
        cin >> ind >> qq;
        ind--;
        if (qq[0] != '?') {
            auto itr = indices.find(ind);
            if (itr != indices.end() && ind > 0)
                ans = mdiv(ans,ind);
            indices.erase(ind);
        } else {
            auto itr = indices.find(ind);
            if (itr == indices.end() && ind > 0)
                ans = mmul(ans,ind);
            indices.insert(ind);
        }
        if (indices.find(0) == indices.end())
            cout << ans << "\n";
        else
            cout << 0 << "\n";
    }
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
