#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e5, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}



vector<int>sa(2*N+1,0),sb(2*N+1,0);
void solve() {
	int n,m,q;
    cin >> n >> m >> q;
    ll suma=0,sumb=0;
    vector<int> a(n),b(m); 
    for(auto &num:a)
        cin >> num,suma+=num;
    for(auto &num:b)
        cin >> num,sumb+=num;
    for(auto &num:a)
        if (abs(suma-num)<=N)
            sa[suma-num+N]=1;
    for(auto &num:b)
        if (abs(sumb-num)<=N)
            sb[sumb-num+N]=1;
    while(q--) {
        int x;
        cin >> x;
        bool found = false;
        int absx=abs(x);
        for(int i=1;i*i<=absx&&!found;i++) {
            if (absx%i!=0)
                continue;
            int l = i, r = absx/i;
            if (x>0) {
                for(pii &pp:vector<pii>{{l,r},{r,l},{-l,-r},{-r,-l}}) {
                    int ca=pp.F+N, cb=pp.S+N;
                    if (sa[ca]==1 && sb[cb]==1) {
                        found=true;
                        break;
                    }
                }
            } else {
                for(pii &pp:vector<pii>{{-l,r},{l,-r},{-r,l},{r,-l}}) {
                    int ca=pp.F+N, cb=pp.S+N;
                    if (sa[ca]==1 && sb[cb]==1) {
                        found=true;
                        break;
                    }
                }
            }
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
