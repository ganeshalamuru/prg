#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<vector<int>> radj(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        radj[arr[i]].push_back(i);
    }
    stack<int> post_order_of_revg;
    vector<int> vis(n+1,0);
    function<void(int)> dfs=[&](int u) {
        vis[u]=1;
        for(int &v:radj[u]) {
            if (vis[v]!=0)
                continue;
            dfs(v);
        }
        post_order_of_revg.push(u);
    };
    for(int i=1;i<=n;i++) {
        if (vis[i]!=0)
            continue;
        dfs(i);
    }
    vector<int> dp(n+1,0);
    while (!post_order_of_revg.empty()) {
        int u = post_order_of_revg.top();
        post_order_of_revg.pop();
        if (dp[u]!=0)
            continue;
        if (dp[arr[u]]!=0) {
            dp[u]=dp[arr[u]]+1;
            continue;
        }
        int numnodesinscc = 1, trav=arr[u];
        while(trav!=u)
            numnodesinscc++,trav=arr[trav];
        dp[u]=numnodesinscc, trav=arr[u];
        while(trav!=u)
            dp[trav]=numnodesinscc,trav=arr[trav];
    }
    for(int i=1;i<=n;i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";

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
