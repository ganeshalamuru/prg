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

int mmul(ll a, ll b) {
    a%=mod, b%=mod;
    return(1ll * a* b)%mod;
}
int mdiv(ll a) {
    a%=mod;
    return powe(a, mod-2);
}

void solve() {
	int n,q;
    cin >> n >> q;
    vector<vector<int>> a(n,vector<int>(2)),b(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    for(int i=0;i<n;i++) {
        cin >> b[i][0];
        b[i][1] = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> aisi(n), bisi(n);
    int prod = 1;
    for(int i=0;i<n;i++) {
        aisi[a[i][1]] = i;
        bisi[b[i][1]] = i; 
        prod =mmul(prod, min(a[i][0], b[i][0]));
    }
    cout << prod << " ";
    while(q--) {
        int o, x;
        cin >> o >> x;
        x--;
        auto cmp = [](const int &v, const vector<int> &arr){return v < arr[0];};
        if (o==1) {
            int si = aisi[x],val = a[si][0];
            int nsi= upper_bound(a.begin(), a.end(), val, cmp)-a.begin();
            nsi = max(0,nsi-1);
            swap(aisi[x], aisi[a[nsi][1]]); 
            swap(a[si], a[nsi]);
            
            int pmin = min(a[nsi][0], b[nsi][0]);
            a[nsi][0]++;
            int nmin = min(a[nsi][0], b[nsi][0]);
            if (pmin!=nmin) {
                prod = mmul(prod, mdiv(pmin));
                prod = mmul(prod, nmin);
            } 
        } else {
            int si = bisi[x],val = b[si][0];
            int nsi= upper_bound(b.begin(), b.end(), val, cmp)-b.begin();
            nsi = max(0,nsi-1);
            swap(bisi[x], bisi[b[nsi][1]]); 
            swap(b[si], b[nsi]);
            int pmin = min(b[nsi][0], a[nsi][0]);
            b[nsi][0]++;
            int nmin = min(b[nsi][0], a[nsi][0]);
            if (pmin!=nmin) {
                prod = mmul(prod, mdiv(pmin));
                prod = mmul(prod, nmin);
            } 
        }
        cout << prod << " ";
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
