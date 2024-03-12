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
	ll n,k;
    cin >> n;
    vector<ll>a(n),sne(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> k;
    stack<int>stk;
    for(int i=n-1;i>=0;i--) {
        while(!stk.empty() && a[stk.top()]>a[i])
            stk.pop();
        if (stk.empty())
            sne[i]=-1;
        else
            sne[i]=stk.top();
        stk.push(i);
    }
    vector<pair<ll,ll>> coins;
    vector<int> ind;
    ll rem = k,used = 0;
    for(int i=0;i<n;i++) {
        if (sne[i]!=-1)
            continue;
        if (coins.empty()) {
            coins.push_back({rem/a[i], a[i]});
            ind.push_back(i);
            used += a[i]*(rem/a[i]);
            rem = k-used;
            continue;
        }
        auto itr = coins.rbegin();
        pair<ll,ll> pp;
        if ((rem / (a[i] - itr->second)) > 0) {
            ll numnew = min(itr->first, rem / (a[i] - itr->second));
            pp = {numnew, a[i]};
            itr->first -= pp.first;
            used += pp.first*(a[i]-itr->second);
            coins.push_back(pp);
            ind.push_back(i);
            rem = k - used;
        } else {
            break;
        }
    }
    vector<ll>pparr(n+1,0);
    for(int i=0;i<coins.size();i++) {
        pparr[0]+=coins[i].first;
        pparr[ind[i]+1]-=coins[i].first;
    }
    ll ele = 0;
    for(int i=0;i<n;i++) {
        ele+=pparr[i];
        cout << ele << " ";
    }
    cout << "\n";
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
