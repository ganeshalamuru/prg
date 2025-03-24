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


bool possible(vector<int>&u,vector<int>&d,int x,int h) {
    int n = u.size();
    for(int i=0;i<n;i++) {
        if (u[i]+d[i]<h)
            return false;
    }
    vector<int>l(n),r(n);
    for(int i=0;i<n;i++) {
        int diff = u[i]+d[i]-h;
        l[i]=max(0,u[i]-diff);
        r[i]=min(u[i],u[i]-(diff-d[i]));
    }
    for(int i=1;i<n;i++) {
        l[i]=max(l[i],l[i-1]-x);
        r[i]=min(r[i],r[i-1]+x);
        if (r[i]<l[i])
            return false;
    }
    return true;
}

void solve() {
	int n,x;
    cin >> n >> x;
    int hmax=INT_MIN;
    ll tot = 0;
    vector<int> u(n),d(n);
    for(int i=0;i<n;i++)
        cin >> u[i] >> d[i],hmax=max(hmax,u[i]+d[i]),tot+=u[i]+d[i];
    int l=0,r=hmax;
    while(l<r) {
        int mid = l+(r-l+1)/2;
        if (possible(u,d,x,mid)) {
            l=mid;
        } else {
            r=mid-1;
        }
    }
    cout << tot-1ll*n*l << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
