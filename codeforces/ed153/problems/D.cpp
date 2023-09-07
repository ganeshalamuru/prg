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
    int n01 = 0, n10 = 0, nz = 0, no = 0;
    for (char ch:s) {
        ch == '0' ? nz++ : no++;
        if (nz>=0 && no >=0)
            ch == '0' ? n10 += no : n01 += nz;
    }
    int moves = 0;
    while(abs(n10 - n01) > 0) {
        int newn10 = n10, newn01 = n01;
        int si, sj;
        for (int i=0;i<s.size();i++) {
            for (int j=i+1;j<s.size();j++) {
                int fac = j-i;
                if (s[i] == '1' && s[j] == '0') {
                    if (abs(newn01 - newn10) > abs((n10 - fac) - (n01 + fac))) {
                        newn01 = n01 + fac, newn10 = n10 - fac;
                        si=i,sj=j;
                    }
                } else if (s[i] == '0' && s[j] == '1') {
                    if (abs(newn01 - newn10) > abs((n10 + fac) - (n01 - fac))) {
                        newn01 = n01 - fac, newn10 = n10 + fac;
                        si=i,sj=j;
                    }
                }
            }
        }
        swap(s[si],s[sj]);
        n10 = newn10, n01 = newn01;
        moves++;
    }
    cout << moves << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
