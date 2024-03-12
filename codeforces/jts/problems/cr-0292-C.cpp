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
    vector<int>primefreq(10,0);
    vector<int> spf{0,1,2,3,2,5,2,7,2,3};
    for(int i=0;i<n;i++) {
        for(int j=2;j<=s[i]-'0';j++) {
            int tmp = j;
            while(tmp>1) primefreq[spf[tmp]]++,tmp/=spf[tmp];
        }
    }
    string res = "";
    for(int j=7;j>=2;j--) {
        while(primefreq[j] > 0) {
            for(int z=j;z>=2;z--) {
                int tmp = z;
                while(tmp>1) primefreq[spf[tmp]]--,tmp/=spf[tmp];
            }
            res.push_back(j+'0');
        }
    }
    cout << res << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
