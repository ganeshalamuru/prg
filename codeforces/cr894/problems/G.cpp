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
	ll n;
    cin >> n;
    vector<ll> a(n);
    set<pair<ll, ll>> sortedarr;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        sortedarr.insert({a[i],i});
    }
    set<pair<ll,pair<ll,ll>>, greater<pair<ll,pair<ll,ll>>>> gg;
    for(auto itr = ++sortedarr.begin(); itr!= sortedarr.end();itr++) {
        auto itrr = itr;
        pair<ll,ll> cur = *itrr;
        pair<ll,ll> prev = *(--itrr);
        ll diff = cur.first - prev.first;
        pair<ll,pair<ll,ll>> ppp = {diff,{max(cur.second, prev.second),min(cur.second, prev.second)}};
        gg.insert(ppp);
    }
    int q;
    cin >> q;
    while(q--) {
        ll ind,x;
        cin >> ind >> x;ind--;
        if (n==1) {
            cout << x << "\n";
            continue;
        }
        pair<ll,ll> pp = {a[ind], ind};
        auto itr = sortedarr.find(pp);
        
        auto prev = itr, next = itr;
        next++;
        if (next != sortedarr.end()) {
            ll diff = next->first - itr->first;
            pair<ll,pair<ll,ll>> ppp = {diff,{max(next->second, itr->second),min(next->second, itr->second)}};
            auto itr3 = gg.find(ppp);
            gg.erase(itr3);
        }
        if (itr != sortedarr.begin()) {
            prev--;
            ll diff = itr->first - prev->first;
            pair<ll,pair<ll,ll>> ppp = {diff,{max(prev->second, itr->second),min(prev->second, itr->second)}};
            auto itr3 = gg.find(ppp);
            gg.erase(itr3);
        }
 
        if (prev != itr && next != sortedarr.end()) {
            ll diff = next->first - prev->first;
            pair<ll,pair<ll,ll>> ppp = {diff,{max(prev->second, next->second),min(prev->second, next->second)}};
            gg.insert(ppp);
        }
        sortedarr.erase({a[ind], ind});
        a[ind]  = x;
        sortedarr.insert({a[ind], ind});
        itr = sortedarr.find({a[ind],ind});
        
        prev = itr, next = itr;
        next++;
        if (next != sortedarr.end()) {
            ll diff = next->first - itr->first;
            pair<ll,pair<ll,ll>> ppp = {diff,{max(next->second, itr->second),min(next->second, itr->second)}};
            gg.insert(ppp);
        }
 
        if (itr != sortedarr.begin()) {
            prev--;
            ll diff = itr->first - prev->first;
            pair<ll,pair<ll,ll>> ppp = {diff,{max(prev->second, itr->second),min(prev->second, itr->second)}};
            gg.insert(ppp);
        }
 
        if (prev != itr && next != sortedarr.end()) {
            ll diff = next->first - prev->first;
            pair<ll,pair<ll,ll>> ppp = {diff,{max(prev->second, next->second),min(prev->second, next->second)}};
            gg.erase(ppp);
        }
 
        cout << gg.begin()->first + sortedarr.rbegin()->first << " ";
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
