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
	string s;
    cin >> s;
    int n = s.size();
    ll pos;
    cin >> pos;
    int lenOfReqStr = n;
    while(pos>lenOfReqStr) {
        pos-=lenOfReqStr;
        lenOfReqStr--;
    }
    stack<int> stk;
    int i=0;
    while(stk.size()+(n-i)>lenOfReqStr) {
        if (i==n) {
            stk.pop();
        } else if (stk.empty()) {
            stk.push(i);
            i++;
        } else if (s[stk.top()] > s[i]) {
            stk.pop();
        } else {
            stk.push(i);
            i++;
        }
    }
    string str = "";
    while(!stk.empty()) str.push_back(s[stk.top()]),stk.pop();
    reverse(str.begin(), str.end());
    while(i<n) str.push_back(s[i]),i++;
    cout << str[pos-1];

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
