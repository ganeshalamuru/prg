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
	string str;
    cin >> str;
    stack<char> stk;
    stk.push('0');
    int i = 0;
    while (i < str.size()) {
        if (str[i]-'0' >= 5) {
            char tpp = stk.top();
            stk.pop();
            stk.push(tpp+1);
            break;
        } else {
            stk.push(str[i]);
        }
        i++;
    }
    while (!stk.empty() && stk.top()-'0' >= 5) {
        stk.pop();
        char tpp = stk.top();
        stk.pop();
        stk.push(tpp+1);
    }
    string res = "";
    while(!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    if (res.back() == '0') {
        res.pop_back();
        reverse(res.begin(), res.end());
        int diff = str.size() - res.size();
        while(diff--) res.push_back('0');
        std::cout << res << "\n";
    } else {
        reverse(res.begin(), res.end());
        int diff = str.size() - res.size() + 1;
        while(diff--) res.push_back('0');
        std::cout << res << "\n";
    }

}




signed main(){
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
