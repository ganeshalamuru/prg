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


vector<int> bit;
void update(int i) {
    int n = bit.size()-1;
    while(i<=n) {
        bit[i]++;
        i+=(i - (i&(i-1)));
    }
}
int query(int i) {
    int sum = 0, temp=bit.size()-1;
    while(temp>0) {
        sum+=bit[temp];
        temp=(temp&(temp-1));
    }
    temp=i;
    while(temp>0) {
        sum-=bit[temp];
        temp=(temp&(temp-1));
    }
    return sum;
}
void dfs(int u, int p, vector<vector<int>>&adj, vector<int> &dp, vector<int>&arr) {
    dp[u]-=query(arr[u]);
    for(int &v:adj[u]) {
        if (v==p)
            continue;
        dfs(v, u, adj, dp, arr);
    }
    update(arr[u]);
    dp[u]+=query(arr[u]);
}

void solve() {
	int n;
    cin >> n;
    bit = vector<int>(n+1, 0);
    vector<int> arr(n);
    map<int,vector<int>> freq;
    for(int i=0;i<n;i++)
        cin >> arr[i],freq[arr[i]].push_back(i);
    vector<vector<int>>adj(n);
    for(int i=0,u,v;i<n-1;i++) {
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dp(n);
    dfs(0, -1, adj, dp, arr);
    int pfreq = 0;
    for(auto itr=freq.rbegin();itr!=freq.rend();itr++) {
        for(int &node:itr->second) {
            if (dp[node]!=pfreq) {
                cout << node+1 << "\n";
                return;
            }
        }
        pfreq+=itr->S.size();
    }
    cout << 0 << "\n";
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
