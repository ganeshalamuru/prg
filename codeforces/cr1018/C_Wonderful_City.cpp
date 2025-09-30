#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;

ll solvee(int n,vector<vector<int>>&grid, vector<int>&rowcost) {

    vector<pii> segments;
    vector<vector<ll>> cost;
    int ii=0;
    while(ii<n) {
        vector<ll>trowcost(2,0);
        trowcost[0]+=rowcost[ii];
        int j=ii+1;
        segments.push_back({ii,j-1});
        cost.push_back(trowcost);
        ii=j;
    }
    vector<vector<int>> opinvalid(segments.size(),vector<int>(2,0));
    for(int i=0;i<segments.size();i++) {
        for(int j=segments[i].F;j<=segments[i].S;j++) {
            for(int z=0;z<n;z++) {
                if (j-1>=segments[i].F) {
                    if (grid[j-1][z]==grid[j][z]+1) {
                        opinvalid[i][(j-segments[i].F)%2]=1;
                    }
                }
                if (j+1<=segments[i].S) {
                    if (grid[j+1][z]==grid[j][z]+1) {
                        opinvalid[i][(j-segments[i].F)%2]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<segments.size();i++) {
        if (segments[i].S-segments[i].F>0) {
            if (opinvalid[i][0]==1 && opinvalid[i][1]==1) {
                return LLONG_MAX;
            }
        }
    }
    vector<vector<ll>> dp(segments.size(),vector<ll>(2,LLONG_MAX));
    if(opinvalid[0][0]!=1)
        dp[0][0]=cost[0][0];
    if (opinvalid[0][1]!=1)
        dp[0][1]=cost[0][1];
    for(int i=1;i<segments.size();i++) {

        bool voila = false;
        for(int j=0;j<n;j++) {
            if (grid[segments[i].F-1][j]==grid[segments[i].F][j]+1) {
                voila = true;
                break;
            }
        }
        int psz = segments[i-1].S-segments[i-1].F;
        if (voila) {
            if (opinvalid[i][0]!=1 && dp[i-1][psz%2]!=LLONG_MAX) {
                dp[i][0]=min(dp[i][0], cost[i][0]+dp[i-1][psz%2]);
            }
        } else {
            if (opinvalid[i][0]!=1 && dp[i-1][(psz%2)^1]!=LLONG_MAX) {
                dp[i][0]=min(dp[i][0], cost[i][0]+dp[i-1][(psz%2)^1]);
            }
        }
        bool v2 = false;    
        for(int j=0;j<n;j++) {
            if (grid[segments[i].F-1][j]+1==grid[segments[i].F][j]) {
                v2 = true;
                break;
            }
        }
        if (opinvalid[i][1]!=1 && dp[i-1][(psz%2)^1]!=LLONG_MAX)
            dp[i][1]=min(dp[i][1],cost[i][1] + dp[i-1][(psz%2)^1]);
        if (opinvalid[i][1]!=1 && !v2 && dp[i-1][psz%2]!=LLONG_MAX) {
            dp[i][1] = min(dp[i][1],cost[i][1]+dp[i-1][psz%2]);
        }
    }
    return min(dp[segments.size()-1][0], dp[segments.size()-1][1]);
}

void solve() {
	int n;
    cin >> n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> rowcost(n),colcost(n);
    for(int i=0;i<n;i++)
        cin >> rowcost[i];
    for(int i=0;i<n;i++)
        cin >> colcost[i];
    ll ans1 = solvee(n,grid,rowcost);
    vector<vector<int>> grid2(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            grid2[i][j]=grid[j][i];
        }
    }
    ll ans2 = solvee(n,grid2,colcost);
    if (ans1==LLONG_MAX || ans2 == LLONG_MAX) {
        cout << -1 << "\n";
    } else {
        cout << ans1 + ans2 << "\n";
    }


}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
