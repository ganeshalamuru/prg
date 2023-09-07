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
	int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k%2==0) {
        sort(s.begin(), s.end());
        cout << s << "\n";
    } else {
        string even, odd;
        for(int i=0;i<n;i++) {
            if(i%2==0){
                even.push_back(s[i]);
            } else {
                odd.push_back(s[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        string res = "";
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                res.push_back(even[i/2]);
            } else {
                res.push_back(odd[i/2]);
            }
        }
        cout << res << "\n";
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
