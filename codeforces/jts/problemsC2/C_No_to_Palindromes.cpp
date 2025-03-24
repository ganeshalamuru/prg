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
	int n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    int j = n-1;
    while(j>=0) {
        vector<int> prv(p,0);
        if (j-1>=0)
            prv[s[j-1]-'a']=1;
        if (j-2>=0)
            prv[s[j-2]-'a']=1;
        int ch = (s[j]-'a')+1;
        while(ch<p) {
            if (prv[ch]!=1) {
                s[j]='a'+ch;
                break;
            }
            ch++;
        }
        if (ch!=p)
            break;
        j--;
    }
    if (j<0) {
        cout << "NO\n";
        return;
    }
    j++;
    while(j<n) {
        vector<int> prv(p,0);
        if (j-1>=0)
            prv[s[j-1]-'a']=1;
        if (j-2>=0)
            prv[s[j-2]-'a']=1;
        int ch = 0;
        while(ch<p) {
            if (prv[ch]!=1) {
                s[j]='a'+ch;
                break;
            }
            
            ch++;
        }
        if (ch==p)
            break;
        j++;
    }
    if (j!=n)
        cout << "NO\n";
    else
        cout << s << "\n";


}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
