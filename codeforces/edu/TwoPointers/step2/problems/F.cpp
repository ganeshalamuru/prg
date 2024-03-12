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


stack<ll> s[2],smax[2],smin[2];

void push(int stk,ll a) {
    if (s[stk].empty()) {
        s[stk].push(a);
        smin[stk].push(a);
        smax[stk].push(a);
    } else {
        s[stk].push(a);
        smin[stk].push(min(a,smin[stk].top()));
        smax[stk].push(max(a, smax[stk].top()));
    }
}


void pop(int stk) {
    if (s[stk].empty()) {
        while(!s[stk^1].empty())
            push(stk, s[stk^1].top()), s[stk^1].pop();
    }
    s[stk].pop();
    smin[stk].pop();
    smax[stk].pop();
}

ll diff() {
    ll maxe = LLONG_MIN;
    if (!s[0].empty())
        maxe = max(maxe, smax[0].top());
    if (!s[1].empty())
        maxe = max(maxe, smax[1].top());
    ll mine = LLONG_MAX;
        if (!s[0].empty())
        mine = min(mine, smin[0].top());
    if (!s[1].empty())
        mine = min(mine, smin[1].top());
    return maxe - mine;
}


void solve(){
	int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &i: a)
        cin >> i;
    int i=0,j=0;
    ll goodcnt = 0;
    while(j<n) {
        push(1,a[j]);
        while(i<j && diff()>k) pop(0), i++;
        goodcnt+=(j-i+1);
        j++;
    }
    cout << goodcnt << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
