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
	int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(2*m+1),radj(2*m+1);
    auto getoppnode=[&](int u) {
        return ((u-1+m)%(2*m))+1;
    };
    string s;
    getline(cin,s);
    for(int i=0,u,v;i<n;i++) {
        getline(cin,s);
        stringstream ss(s);
        auto getnode = [&](){
            char ch;
            int val;
            ss >> ch >> val;
            if (ch=='-')
                val+=m;
            return val; 
        };
        u = getnode(),v = getnode();
        adj[getoppnode(u)].push_back(v);
        adj[getoppnode(v)].push_back(u);
        radj[v].push_back(getoppnode(u));
        radj[u].push_back(getoppnode(v));
    }
    vector<int> vis(2*m+1,0);
    vector<int> postorder_of_revg;
    function<void(int)> dfs=[&](int u) {
        vis[u]=1;
        for(int v:radj[u]) {
            if (vis[v]==0)
                dfs(v);
        }
        postorder_of_revg.push_back(u);
    };
    for(int i=1;i<=2*m;i++) {
        if (vis[i]==0)
            dfs(i);
    }
    fill(all(vis),0);
    int compno=0;
    vector<int> valuation(2*m+1,-1);
    while(!postorder_of_revg.empty()) {
        int node = postorder_of_revg.back();
        postorder_of_revg.pop_back();
        if (vis[node]!=0)
            continue;
        compno++;
        vector<int> compnodes;
        int valuaneighcomp = -1;
        function<void(int)> dfs2 = [&](int u) {
            vis[u]=compno;
            compnodes.push_back(u);
            for(int v:adj[u]) {
                if (vis[v]==0)
                    dfs2(v);
                else if(vis[v]!=compno) {
                    valuaneighcomp=valuation[v];
                } 
            }
        };
        dfs2(node);
        int valuacomp = -1;
        for(int v:compnodes) { 
            if (vis[v]==vis[getoppnode(v)]) {
                cout << "IMPOSSIBLE\n";
                return;
            }
            if (valuation[v]!=-1) {
                valuacomp=valuation[v];
                break;
            }
        }
        if (valuacomp==-1) {
            if (valuaneighcomp!=-1)
                valuacomp=valuaneighcomp;
            else
                valuacomp=1;
        }
        for(int v:compnodes) {
            int oppnode = getoppnode(v);
            valuation[v]=valuacomp;
            valuation[oppnode]=valuacomp^1;
        }
    }
    for(int i=1;i<=m;i++) {
        if (valuation[i]==0) {
            cout << "- ";
        } else {
            cout << "+ ";
        }
    }
    cout << "\n";


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
