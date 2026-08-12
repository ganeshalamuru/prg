#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;



void solve() {
	int n,k;
    cin >> n >> k;
    vector<string> grid(n);
    for(int i=0;i<n;i++) {
        cin >> grid[i];
    }
    vector<ll> ans(k,0);
    vector<vector<ll>> dp(n,vector<ll>(n));
    for(int z=0;z<n;z++)
        dp[0][z]=dp[z][0]=1;
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            if (grid[i][j-1]==grid[i-1][j] && grid[i][j]==grid[i][j-1]) {
                if (dp[i][j-1]==dp[i-1][j]) {
                    ll tmp = dp[i][j-1];
                    if (grid[i-tmp][j-tmp]==grid[i][j]) {
                        dp[i][j]=1+tmp;
                    } else {
                        dp[i][j]=tmp;
                    }
                } else {
                    dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
                }
            } else {
                dp[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans[grid[i][j]-'A']+=dp[i][j];
        }
    }
    for(auto a:ans) {
        cout << a << "\n";
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
