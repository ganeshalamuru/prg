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
	int n;
    cin >> n;
    vector<vector<pair<char,int>>> gates(n,vector<pair<char,int>>(2));
    for(int i=0;i<n;i++) {
        string op;
        int num;
        cin >> op >> num;
        gates[i][0]={op[0], num};
        cin >> op >> num;
        gates[i][1]={op[0], num};
    }
    vector<int> ch(n);
    int prev = 0;
    for(int i=n-1;i>=0;i--) {
        if (gates[i][0].F=='x' && gates[i][1].F=='x') {
            if (gates[i][0].S>gates[i][1].S)
                ch[i]=0;
            else if (gates[i][0].S<gates[i][1].S)
                ch[i]=1;
            else
                ch[i]=prev;
        } else if (gates[i][0].F=='x' && gates[i][1].F == '+') {
            ch[i]=0;
        } else if (gates[i][0].F=='+' && gates[i][1].F == 'x') {
            ch[i]=1;
        } else {
            ch[i]=prev;
        }
        prev = ch[i];
    }
    pair<ll,ll> ans{1,1};
    for(int i=0;i<n;i++) {
        pair<ll,ll> delta={0,0};
        if (gates[i][0].F=='x') {
            delta.F = (gates[i][0].S-1)*ans.F;
        } else {
            delta.F = gates[i][0].S;
        }

        if (gates[i][1].F=='x') {
            delta.S = (gates[i][1].S-1)*ans.S;
        } else {
            delta.S = gates[i][1].S;
        }
        if (i+1>=n) {
            ans.F+=delta.F+delta.S;
        } else if (ch[i+1]==0)
            ans.F+=delta.F+delta.S;
        else
            ans.S+=delta.F+delta.S;
    }
    cout << ans.F+ans.S << "\n";
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
