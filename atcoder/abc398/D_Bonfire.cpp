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
	int n,r,c;
    cin >> n >> r>>c;
    string s;
    cin >> s;
    vector<pii> arr(n);
    map<char,pii> mp{{'N',{-1,0}},{'W',{0,-1}},{'S',{1,0}},{'E',{0,1}}};
    for(int i=0;i<n;i++) {
        arr[i]=mp[s[i]];
    }
    set<pii> ss;
    ss.insert({0,0});
    int dx=0,dy=0;
    for(int i=0;i<n;i++) {
        dx+=arr[i].F, dy+=arr[i].S;
        int reqx = dx-r,reqy = dy-c;
        if (ss.find({reqx,reqy})!=ss.end()) {
            cout << 1;
        } else {
            cout << 0;
        }
        ss.insert({dx,dy});
    }
    cout << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
