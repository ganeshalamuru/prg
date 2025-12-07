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
    vector<set<int>> adj(n+1);
    for(int i=1,a,b;i<=m;i++) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    if (find_if(all(adj),[](const auto &a){return (a.size()%2)!=0;})!=adj.end()) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> vis(n+1, 0);
    function<void(int)> dfs = [&](int u) {
        vis[u]=1;
        for(int v:adj[u]) {
            if (vis[v]==0)
                dfs(v);
        }
    };
    dfs(1);
    for(int i=1;i<=n;i++) {
        if (vis[i]==0 && adj[i].size()>0) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    fill(all(vis),0);
    vector<vector<int>> cycles;
    vector<set<int>> nodecyclelist(n+1);
    for(int i=1;i<=n;i++) {
        if (adj[i].empty())
            continue;
        stack<int> stk;
        stk.push(i);
        set<int> pathv{i};
        while(!stk.empty()) {
            int u = stk.top();
            int v = *adj[u].begin();
            adj[v].erase(u);
            if (pathv.find(v)==pathv.end()) {
                pathv.insert(v);
                stk.push(v);
                continue;
            }
            int prev = v;
            vector<int> cycle{v};
            while (stk.top()!=v) {
                cycle.push_back(stk.top());
                adj[stk.top()].erase(prev);
                pathv.erase(stk.top());
                prev = stk.top();
                stk.pop();
            }
            adj[stk.top()].erase(prev);
            if (adj[stk.top()].empty())
                pathv.erase(stk.top()),stk.pop();
            reverse(all(cycle));
            for(int node:cycle) {
                nodecyclelist[node].insert(int(cycles.size()));
            }
            cycles.push_back(cycle);
        }   
    }
    vector<int> eulercycle;
    function<void(int)> dfs2 = [&](int u) {
        while(!nodecyclelist[u].empty()) {
            auto cyclenum = *nodecyclelist[u].begin();
            for(int v:cycles[cyclenum])
                nodecyclelist[v].erase(cyclenum);
            auto itr = find(cycles[cyclenum].begin(), cycles[cyclenum].end(), u);
            int ind=int(distance(cycles[cyclenum].begin(), itr));

            int cycsz=int(cycles[cyclenum].size());
            if (eulercycle.empty() || eulercycle.back()!=u)
                eulercycle.push_back(u);
            for(int i=(ind+1)%cycsz,cnt=1;cnt<cycsz;cnt++,i=(i+1)%cycsz) {
                int v = cycles[cyclenum][i]; 
                dfs2(v);
                if (eulercycle.back()!=v)
                    eulercycle.push_back(v);
            }
            if (eulercycle.empty() || eulercycle.back()!=u)
                eulercycle.push_back(u);
        }
    };
    dfs2(1);
    for(int node:eulercycle) {
        cout << node << " ";
    }
    cout << "\n";

}



void solve2() {
    int n,m;
    cin >> n >> m;
    vector<set<int>> adj(n+1);
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for(int i=1;i<=n;i++) {
        if ((adj[i].size())%2 != 0) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    vector<int> vis(n+1);
    function<void(int)> dfs = [&](int u) {
        vis[u]=1;
        for(int v:adj[u]) {
            if (vis[v]==0)
                dfs(v);
        }
    };
    dfs(1);
    for(int i=1;i<=n;i++) {
        if (vis[i]==0 && !adj[i].empty()) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    vector<int> eulercycle;
    function<void(int)> dfs2 = [&](int u) {
        while(!adj[u].empty()) {
            auto v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            dfs2(v);
        }
        eulercycle.push_back(u);
    };
    dfs2(1);
    for(int node:eulercycle) {
        cout << node << " ";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	// solve();
        solve2();
    }
    
    return 0;
}
