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
    string s,r;
    cin >> s >> r;
    int onecnt=(s[n-1]=='1'), zerocnt=(s[n-1]=='0');
    int i=n-2;
    while (i>=0) {
        onecnt+=(s[i]=='1'),zerocnt+=(s[i]=='0');
        if (s[i]==s[i+1]) {
            i--;
            continue;
        }
        if (s[i]==r[i]) {
            onecnt=0,zerocnt=0;
            s[i]=r[i];
            onecnt+=(r[i]=='1'),zerocnt+=(r[i]=='0');
            i--;
        } else {
            int schar = s[i]-'0', rchar = r[i]-'0', j=i;
            while(j>=0 && s[j]==('0'+schar) && r[j]==('0' + rchar)) {
                schar^=1,rchar^=1;
                j--;
            }
            if (i-j>=2) {
                onecnt=0,zerocnt=0;
                onecnt+=(r[j+1]=='1'),zerocnt+=(r[j+1]=='0');
            } else if(s[i]=='0') {
                zerocnt--;
            } else {
                onecnt--;
            }
            s[j+1]=r[j+1];
            i=j;
        }
    }
    
    if (onecnt+zerocnt==1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
