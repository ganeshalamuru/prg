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
    int m;
    cin >> m;
    string lstr,rstr;
    cin >> lstr >> rstr;
    vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(m,vector<int>(10,0)));
    vector<vector<int>> dp2(s.size(),vector<int>(m,0));
    
    for(int i=0;i<s.size();i++) {
        for(int j=0;j<m;j++) {
            for (int k=0;k<10;k++) {
                if (lstr[j]-'0' > k || rstr[j]-'0' < k)
                    continue;
                if (j > i) {
                    dp[i][j][k] = 1;
                    continue;
                }
                if (i==0) {
                    dp[i][j][k] =  s[i]-'0'!=k;
                    continue;
                }
                if (s[i]-'0'==k) {
                    if (j-1>=0)
                        dp[i][j][k] = dp2[i-1][j-1];
                } else {
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
            for (int k=0;k<10;k++) dp2[i][j] = max(dp2[i][j], dp[i][j][k]);
        }
    }
    int possible = 0;
    for (int k=0;k<10;k++)
        possible = max(possible, dp[s.size()-1][m-1][k]);
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

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