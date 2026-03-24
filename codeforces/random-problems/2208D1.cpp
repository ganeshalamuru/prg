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


bool dfs(int u, vector<vector<int>>&adj, vector<int>&vis, vector<int>&postorder) {
    vis[u]=1;
    for(int v:adj[u]) {
        if (vis[v]==1) {
            return true;
        } else if (vis[v]==2) {
            continue;
        }
        if (dfs(v,adj,vis,postorder))
            return true;
    }
    vis[u]=2;
    postorder.push_back(u);
    return false;
}

void dfs2(int u, vector<vector<int>>&adj, vector<int>&vis) {
    vis[u]=1;
    for(int v:adj[u]) {
        if (vis[v]!=0)
            continue;
        dfs2(v,adj,vis);
    }
}

void solve() {
	int n;
    cin >> n;
    vector<vector<int>> adj(n+1),mat(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) {
        string str;
        cin >> str;
        for(int j=1;auto ch:str) {
            if (ch=='1') {
                mat[i][j]=1;
                if (j!=i)
                    adj[i].push_back(j);
            }
            j++;
        }
    }
    for(int i=1;i<=n;i++) {
        if (mat[i][i]!=1) {
            cout << "No\n";
            return;
        }
    }
    vector<int> vis(n+1,0),postorder;
    for(int i=1;i<=n;i++) {
        if (vis[i]!=0)
            continue;
        if (dfs(i,adj,vis,postorder)) {
            cout << "No\n";
            return;
        }
    }
    vector<vector<int>> fadj(n+1,vector<int>(n+1,0));
    vector<vector<int>> rechability(n+1);
    int numedges = 0;
    for(int i=0;i<n;i++) {
        fill(all(vis),0);
        for(int j=i-1;j>=0;j--) {
            if (vis[postorder[j]]!=0)
                continue;
            if (mat[postorder[i]][postorder[j]]==1) {
                numedges++;
                fadj[postorder[i]][postorder[j]]=1;
                dfs2(postorder[j],adj,vis);
            }
        }
        for(int j=1;j<=n;j++) {
            if (postorder[i]==j)
                continue;
            if (mat[postorder[i]][j]!=vis[j]) {
                cout << "No\n";
                return;
            }
        }

    }
    if (numedges != n-1) {
        cout << "No\n";
        return;
    }
    vector<vector<int>> ffadj(n+1);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if (fadj[i][j])
                ffadj[i].push_back(j),ffadj[j].push_back(i);
        }
    }
    fill(all(vis),0);
    dfs2(1,ffadj,vis);
    for(int i=1;i<=n;i++) {
        if (vis[i]==0) {
            cout << "No\n";
            return;
        }
    }


    cout << "Yes\n";
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if (fadj[i][j])
                cout << i << " " << j << "\n";
        }
    }

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
