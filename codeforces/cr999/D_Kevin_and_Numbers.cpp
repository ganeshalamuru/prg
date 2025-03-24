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
	int n,m;
    cin >> n >> m;
    set<pair<ll,ll>,greater<pair<ll,ll>>> ss;
    map<ll,ll> freqa, freqb;
    for(int i=0,x;i<n;i++)
        cin >> x,freqa[x]++;
    for(int j=0,x;j<m;j++)
        cin >> x,freqb[x]++;
    for(auto &pp:freqb)
        ss.insert({pp.F, pp.S});
    while(!ss.empty() && !freqa.empty() && freqa.rbegin()->first<=ss.begin()->first) {
        auto tt = *ss.begin();
        ss.erase(ss.begin());
        if (freqa.find(tt.F) != freqa.end()) {
            int mm = min(freqa[tt.F], tt.S);
            freqa[tt.F]-=mm;
            freqb[tt.F]-=mm;
            tt.S-=mm;
            if (freqa[tt.F]>0) {
                cout << "NO\n";
                return;
            }
            freqa.erase(tt.F);
        }
        freqb.erase(tt.F);
        if (tt.S==0)
            continue;
        if (tt.F%2==0) {
            int num = tt.F/2;
            if (freqb.find(num) != freqb.end()) {
                ss.erase({num, freqb[num]});
            }
            freqb[num]+=2*tt.S;
            ss.insert({num, freqb[num]});
        } else {
            int t1 = (tt.F-1)/2;
            int t2 = t1+1;
            if (freqb.find(t1) != freqb.end()) {
                ss.erase({t1, freqb[t1]});
            }
            if (freqb.find(t2) != freqb.end()) {
                ss.erase({t2, freqb[t2]});
            }
            freqb[t1]+=tt.S;
            freqb[t2]+=tt.S;
            ss.insert({t1, freqb[t1]});
            ss.insert({t2, freqb[t2]});
        }
    }
    if (!ss.empty() || !freqa.empty())
        cout << "NO\n";
    else
        cout << "YES\n";

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
