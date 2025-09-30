#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void rec(int r, int n, int flip, vector<vector<int>>&dp, pii state) {
    if (r>=n) {
        dp[flip][state.S]=(dp[flip][state.S]+dp[flip^1][state.F])%mod;
        return;
    }
    // empty slot on current col on row r
    state.F^=(1<<r);
    rec(r+1,n,flip,dp,state);
    state.F^=(1<<r);
    
    // place 2x1 block
    if (r+1<n) {
        state.F^=(1<<r),state.S^=(1<<r);
        state.F^=(1<<(r+1)),state.S^=(1<<(r+1));
        rec(r+2,n,flip,dp,state);
        state.F^=(1<<r),state.S^=(1<<r);
        state.F^=(1<<(r+1)),state.S^=(1<<(r+1));
    }

    //place 1x2 block
    state.S^=(1<<r);
    rec(r+1,n,flip,dp,state);
    state.S^=(1<<r);
    
}

void solve() {
	int n,m;
    cin >> n >> m;
    if ((n*m)%2==1) {
        cout << 0 << "\n";
        return;
    }
    if (n==1) {
        cout << (m%2==0?1:0) << "\n";
        return;
    }
    vector<vector<int>>dp(2,vector<int>(1<<n,0));
    for(int i=0;i<(1<<n);i++) {
        int j=0;
        while(j<n) {
            int onecnt = 0;
            if (((i>>j)&1)==1) {
                while(j<n && ((i>>j)&1)==1)
                    j++,onecnt++;
            }
            if (onecnt%2==1) {
                j--;
                break;
            }
            if (onecnt==0)
                j++;
        }
        dp[0][i]=(j==n);
    }
    for(int j=1;j<m;j++) {
        int ind = j%2;
        for(int i=0;i<(1<<n);i++)
            dp[ind][i]=0;
        rec(0,n,ind,dp,{0,0});
    }
    cout << dp[(m-1)%2][(1<<n)-1] << "\n";
}


int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
