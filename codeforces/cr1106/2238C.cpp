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



void dfs(int u,int p,vector<vector<int>>& adj,vector<int>& h,int& ans) {
    array<int,2> maxh{INT_MIN,INT_MIN};
    for(int v:adj[u]) {
        if (v==p)
            continue;
        dfs(v,u,adj,h,ans);
        h[u]=max(h[u],h[v]+1);
        int curchildh = h[v]+1;
        if (curchildh>maxh[0]) {
            swap(maxh[0],maxh[1]);
            maxh[0]=curchildh;
        } else if (curchildh>maxh[1]) {
            maxh[1]=curchildh;
        }
    }
    int tmpans = 0;
    if (maxh[0] == INT_MIN || maxh[1]==INT_MIN) {
        tmpans++;
    } else if (maxh[0]==maxh[1]) {
        tmpans+=maxh[0]+1;
    } else {
        tmpans+=maxh[1]+1;
    }
    // cout << "u maxes " << maxh[0] << " " << maxh[1] << "\n";
    // cout << "u " << u <<" " << tmpans << "\n";
    ans+=tmpans;
}

void solve() {
	int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=2,p;i<=n;i++) {
        cin >> p;
        adj[p].push_back(i);
    }
    int ans = 0;
    vector<int> h(n+1);
    dfs(1,0,adj,h,ans);
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
