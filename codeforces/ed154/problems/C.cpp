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
    stack<int>sorted, unsorted;
    int curNumElemets = 0;
    for(int i=0;i<n;i++) {
        if (s[i]== '+' || s[i]== '-') {
            if (s[i]=='+') {
                curNumElemets++;
                if (!unsorted.empty() && unsorted.top() < curNumElemets) {
                    if (unsorted.empty() || unsorted.top()!=curNumElemets)
                        unsorted.push(curNumElemets);
                }
            } else {
                curNumElemets--;
                if (!sorted.empty() && sorted.top() > curNumElemets) {
                    sorted.pop();
                    if (sorted.empty() || sorted.top() != curNumElemets)
                        sorted.push(curNumElemets);
                }
                if (!unsorted.empty() && unsorted.top() > curNumElemets) {
                    unsorted.pop();
                }
            }
            continue;
        }
        if (s[i]=='1') {
            if (sorted.empty() || sorted.top()!=curNumElemets)
                sorted.push(curNumElemets);
        } else if (s[i]=='0') {
            if (unsorted.empty() || unsorted.top()!=curNumElemets)
                unsorted.push(curNumElemets);
        }
        if (unsorted.size()>0 &&( unsorted.top()==0 || unsorted.top()==1)) {
            cout << "NO\n";
            return;
        }
        if (sorted.size() > 0 && unsorted.size() >0 && sorted.top() >= unsorted.top()) {
            cout << "NO\n";
            return;
        }
        
    }
    cout << "YES\n";
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
