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
	string s;
    cin >> s;
    int k;
    cin >> k;
    vector<set<int>> forbidden(26,set<int>());
    for(int i=0;i<k;i++) {
        string pair;
        cin >> pair;
        forbidden[pair[0]-'a'].insert(pair[1]-'a');
        forbidden[pair[1]-'a'].insert(pair[0]-'a');
    }
    vector<vector<int>> dp(s.size(), vector<int>(26,INT_MAX));
    dp[0][s[0]-'a']=0;
    for(int i=1;i<s.size();i++){
        // case 1 final string ends with ith character
        // remove all previous characters
        dp[i][s[i]-'a'] = min(dp[i][s[i]-'a'], i);
        // non empty previous characters
        for(int j=0;j<26;j++){
            if (forbidden[s[i]-'a'].find(j) != forbidden[s[i]-'a'].end())
                continue;
            dp[i][s[i]-'a'] = min(dp[i][s[i]-'a'], dp[i-1][j]);
        }
        // case 2 final string doesnt end with ith character
        for(int j=0;j<26;j++) {
            if (dp[i-1][j] != INT_MAX)
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
        }
    }
    int ans = INT_MAX;
    for(int j=0;j<26;j++)
        ans = min(ans, dp[s.size() - 1][j]);
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
