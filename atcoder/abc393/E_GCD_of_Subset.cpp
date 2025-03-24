#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 1e6+1, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}



vector<int> spf(N);

void initspf() {
    for(int i=0;i<N;i++) {
        spf[i]=i;
    }
    for(int i=2;i*i<N;i++) {
        if (spf[i]==i) {
            for(int j=i*i;j<N;j+=i)
                if (spf[j]==j)
                    spf[j]=i;
        }
    }
}

void solve() {
	initspf();
    int n,k;
    cin >> n >> k;
    vector<int> a(n),freq(N,0);
    for(int i=0;i<n;i++)
        cin >> a[i],freq[a[i]]++;
    vector<int> ans(N,1);
    vector<int> cntmult(N,0);
    for(int i=1;i<N;i++) {
        for(int j=i;j<N;j+=i)
            cntmult[i]+=freq[j];
        if (cntmult[i]>=k)
            for(int j=i;j<N;j+=i)
                ans[j]=max(ans[j],i);
    }
    for(int i=0;i<n;i++)
        cout << ans[a[i]] << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
