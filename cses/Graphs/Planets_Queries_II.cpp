#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

const int N = 2e5+1;

vector<vector<int>> dp(N,vector<int>(30));
void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
        cin >> arr[i],dp[i][0]=arr[i];
    for(int j=1;j<30;j++) {
        for(int i=1;i<=n;i++) {
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    vector<int> vis(n+1,-1), incycle(n+1,0);
    vector<int> cycind(n+1,-1), cycsizes(n+1,0), depth(n+1,0);
    int compno = 1;
    for(int i=1;i<=n;i++) {
        if (vis[i]!=-1)
            continue;
        int node = i;
        vector<int> path;
        while (vis[node]==-1) {
            path.push_back(node);
            vis[node]=0;
            node=arr[node];
        }
        auto itr = find(all(path), node);
        // a cycle
        if (vis[node]==0) {
            int cycstind = int(distance(path.begin(), itr)), cind=0; 
            for(int z=cycstind;z<int(path.size());z++,cind++) {
                int v = path[z];
                cycind[v]=cind;
                incycle[v]=1;
                vis[v]=compno;
            }
            cycsizes[compno]=cind;
        }
        if (itr!=path.begin()) {
            itr--;
            int pnode = node, noncycind = int(distance(path.begin(), itr));
            for(int z=noncycind;z>=0;z--) {
                int v = path[z];
                vis[v]=vis[pnode];
                depth[v]=depth[pnode]+1;
                pnode=v;
            }
        }
        if (vis[node]==compno)
            compno++;
    }
    while (q--) {
        int a,b;
        cin >> a >> b;
        if (vis[a]!=vis[b]) {
            cout << -1 << "\n";
            continue;
        }
        if (a==b) {
            cout << 0 << "\n";
            continue;
        }
        if (incycle[a]==1 && incycle[b]==1) {
            
            if (cycind[a] <= cycind[b]) {
                cout << cycind[b]-cycind[a] << "\n";
            } else {
                cout << cycind[b] + cycsizes[vis[a]] - cycind[a] << "\n";
            }
            
        } else if (incycle[a]==1 && incycle[b]==0) {
            cout << -1 << "\n";
        } else if (incycle[a]==0 && incycle[b]==1) {
            int closestcyclenode = a,j=29,dept = depth[a];
            while(dept>0) {
                if (dept&(1<<j)) {
                    closestcyclenode=dp[closestcyclenode][j];
                    dept-=(1<<j);
                }
                j--;
            }
            int cycdis = 0;
            if (cycind[closestcyclenode] <= cycind[b]) {
                cycdis=cycind[b]-cycind[closestcyclenode];
            } else {
                cycdis=cycind[b] + cycsizes[vis[b]] - cycind[closestcyclenode];
            }
            cout << depth[a]+cycdis << "\n";
        } else {
            if (depth[a]<=depth[b]) {
                cout << -1 << "\n";
            } else {
                int diff = depth[a]-depth[b];
                int ancestora=a,j=29;
                while(diff>0) {
                    if (diff&(1<<j)) {
                        ancestora=dp[ancestora][j];
                        diff-=(1<<j);
                    }
                    j--;
                }
                if (b==ancestora) {
                    cout << depth[a]-depth[b] << "\n";
                } else {
                    cout << -1 << "\n";
                }
            }
        }
    }

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
