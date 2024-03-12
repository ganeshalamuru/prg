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

stack<ll> s[2],gcdd[2];

void push(int stk, ll a) {
    if (s[stk].empty()) {
        s[stk].push(a);
        gcdd[stk].push(a);
    } else {
        s[stk].push(a);
        gcdd[stk].push(__gcd(a, gcdd[stk].top()));
    }
}

void pop(int stk) {
    if (s[stk].empty()) {
        while(!s[stk^1].empty())
            push(stk, s[stk^1].top()), s[stk^1].pop(), gcdd[stk^1].pop();
    }
    s[stk].pop();
    gcdd[stk].pop();
}

ll getgcd() {
    if (!s[0].empty() && !s[1].empty()) {
        return __gcd(gcdd[0].top(), gcdd[1].top());
    } else if (!s[0].empty()) {
        return gcdd[0].top();
    } else {
        return gcdd[1].top();
    }
}


void solve(){
	int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &i:a)
        cin >> i;
    int i=0,j=0, shortest = INT_MAX;
    while(j<n) {
        push(1, a[j]);
        while(i<=j && getgcd()==1) {
            shortest = min(shortest, j-i+1);
            pop(0);
            i++;
        }
        j++;
    }
    if (shortest == INT_MAX)
        cout << -1 << "\n";
    else
        cout << shortest << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
