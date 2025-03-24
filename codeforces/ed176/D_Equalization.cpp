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
 
 
vector<vector<vector<int>>> dp(60,vector<vector<int>>(60,vector<int>(2,INT_MAX)));
 
void solve(ll x, ll y) {
    if (x==y) {
        cout << 0 << "\n";
        return;
    }
    if (x>y)
        swap(x,y);
    bitset<57>bsx(x),bsy(y);
    int i=56,j=56;
    while(i>=0 && bsx[i]==0)
        i--;
    while(j>=0 && bsy[j]==0)
        j--;
    if (x==0) {
        ll cost = 0;
        int moves = j+1;
        while(moves>0) {
            cost|=(1ll<<(dp[0][moves][1]));
            moves-=dp[0][moves][1];
        }
        cout << cost << "\n";
        return;
    }
    int mx=0,my=j-i;
    int minop = INT_MAX, mxx=mx,myy=my;
    while(mx<=i) {
        if ((x>>mx) == (y>>my) && dp[mx][my][1]!=INT_MAX) {
            if (minop > dp[mx][my][1]) {
                minop=dp[mx][my][1];
                mxx=mx,myy=my;
            }
        }
        mx++,my++;
    }
    // someting
    while(my<58) {
        for(int g=mx;g<58;g++) {
            if (minop > dp[mx][my][1]) {
                minop=dp[mx][my][1];
                mxx=mx,myy=my;
            }
        }
        my++;
    }

    ll cost = 0;
    while (mxx>0 || myy>0) {
        cost|=(1ll<<dp[mxx][myy][1]);
        if (myy-dp[mxx][myy][1]>=0 && mxx-dp[mxx][myy][1]>=0) {
            if (dp[mxx][myy-dp[mxx][myy][1]][1] < dp[mxx-dp[mxx][myy][1]][myy][1]) {
                myy-=dp[mxx][myy][1];
            } else {
                mxx-=dp[mxx][myy][1];
            }
        } else if (myy-dp[mxx][myy][1]>=0) {
            myy-=dp[mxx][myy][1];
        } else {
            mxx-=dp[mxx][myy][1];
        }
    }
    cout << cost << "\n";
 
}
 
 
 
 
signed main() {
    fast;
    int t = 1000;
    cin >> t;
    int flip=1;
    for(int z=1;z<58;z++) {
        for(int i=1;i<58;i++) {
            if (dp[i][0][flip^1]!=INT_MAX) {
                dp[i][0][flip]=dp[i][0][flip^1];
                dp[0][i][flip]=dp[0][i][flip^1];
                continue;
            }
            int sum = 0;
            for(int w=1;w<=z;w++)
                sum+=w;
            if (sum>=i)
                dp[i][0][flip]=dp[0][i][flip]=z;
        }
        
        for(int i=1;i<58;i++) {
            for(int j=1;j<58;j++) {
                if (dp[i][j][flip^1]!=INT_MAX) {
                    dp[i][j][flip]=dp[i][j][flip^1];
                    continue;
                }
                if (i-z>=0 && dp[i-z][j][flip^1]!=INT_MAX)
                    dp[i][j][flip]=z;
                if (j-z>=0 && dp[i][j-z][flip^1]!=INT_MAX)
                    dp[i][j][flip]=z;
            }
        }
        flip^=1;
    }
    // std::random_device dev;
    // std::mt19937 rng(dev());
    // std::uniform_int_distribution<std::mt19937::result_type> dist(1,1e9); // distribution in range [1, 6]
    while(t--){
        ll x, y;
        cin >> x >> y;
        // x=dist(rng),y=dist(rng);
        // cout << x << " " << y << "\n";
    	solve(x,y);
    }
    return 0;
}