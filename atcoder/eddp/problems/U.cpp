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
	int n;
    cin >> n;
    vector<vector<ll>> score(n,vector<ll>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> score[i][j];
    vector<ll> dp(1<<n,0),ss(1<<n,0);
    for(int i=1;i<(1<<n);i++) {
        int msbbitpos = 0,tmp=i;
        while(tmp!=1) tmp>>=1, msbbitpos++;
        ss[i] += ss[(1<<msbbitpos)^i];
        tmp = 1;
        int pos = 0;
        while(tmp<=(1<<msbbitpos)) {
            if (tmp&i)
                ss[i] += score[pos][msbbitpos];
            tmp<<=1, pos++;
        }
    }

    for(int i=1;i<(1<<n);i++) {
        int onlymsbset = 1,tmp=i,numbitswoutmsb=0;
        while(tmp!=1) numbitswoutmsb+=(tmp&1), onlymsbset<<=1, tmp>>=1;
        int msbnotset = i^(onlymsbset);
        for(int j=0;j<(1<<numbitswoutmsb);j++) {
            int rr = 0, bittoset = onlymsbset>>1;
            while(bittoset > 0 && (bittoset&msbnotset)==0) bittoset>>=1;
            tmp=j;
            while(tmp > 0) {
                if (tmp&1)
                    rr|=bittoset;
                tmp>>=1;
                bittoset>>=1;
                while(bittoset > 0 && (bittoset&msbnotset)==0) bittoset>>=1;
            }
            int considered = onlymsbset|rr;
            dp[i] = max(dp[i], ss[considered] + dp[i^considered]);
        }
    }
    cout << dp[(1<<n) - 1] << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
