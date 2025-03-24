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


vector<vector<vector<int>>> dp((1<<18),vector<vector<int>>(2,vector<int>(19,0)));
void solve() {
	int h,w;
    cin >> h >> w;
    vector<int> arr(h);
    vector<int> cnt(1<<w,0);
    for(int i=0;i<h;i++) {
        string s;
        cin >> s;
        bitset<18>bs(s);
        arr[i]=bs.to_ulong();
        cnt[arr[i]]++;
    }
    // dp[X][j][c]
    
    for(int x=0;x<(1<<w);x++) {
        dp[x][0][0]=cnt[x];
    }
    int flip=1;
    for(int j=1;j<=w;j++) {
        for(int x=0;x<(1<<w);x++)
            dp[x][flip][0]=cnt[x];
        for(int c=1;c<=w;c++) {
            for(int x=0;x<(1<<w);x++) {
                dp[x][flip][c] = dp[x][flip^1][c] + dp[x^(1<<(j-1))][flip^1][c-1];
            }
        }
        flip^=1;
    }
    int ans = INT_MAX;
    for(int x=0;x<(1<<w);x++) {
        int tans = 0;
        for(int c=0;c<=w;c++) {
            tans+=dp[x][w%2][c]*min(c,w-c);
        }
        ans = min(ans, tans);
    }
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
