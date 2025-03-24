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
	int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char>ss;
    for(int i=0;i<n;i++)
        ss.insert(s[i]);
    int i=0,j=n-1;
    while(i<j && s[i]==s[j])
        i++,j--;
    if (i>=j) {
        if (ss.size()==1 || k==0)
            cout << "NO\n";
        else
            cout << "YES\n";
    } else if (s[i]<s[j] || k>=1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
