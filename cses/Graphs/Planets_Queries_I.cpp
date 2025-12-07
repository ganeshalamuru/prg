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
        cin >> arr[i];
    vector<int> vis(n+1);
    for(int i=1;i<=n;i++) {
        if (vis[i]!=0)
            continue;
        int node = i;
        vector<int> path;
        while (vis[node]==0) {
            path.push_back(node);
            vis[node]=1;
            node=arr[node];
        }
        auto itr = find(all(path), node);
        // a cycle
        if (vis[node]==1) {
            int cycstind = int(distance(path.begin(), itr)); 
            int cycsz = int(distance(itr, path.end()));
            for(int z=cycstind;z<ssize(path);z++) {
                for(int j=0;j<30;j++)
                    dp[path[z]][j]=path[cycstind+(z-cycstind+(1<<j))%cycsz];    
            }
        }
        if (itr!=path.begin()) {
            itr--;
            int pnode = node, noncycind = int(distance(path.begin(), itr));
            for(int z=noncycind;z>=0;z--) {
                dp[path[z]][0]=pnode;
                for(int j=1;j<30;j++) {
                    dp[path[z]][j]=dp[dp[path[z]][j-1]][j-1];
                }
                pnode=path[z];
            }
        }
        int trav=i;
        while(vis[trav]==1) {
            vis[trav]=2;
            trav=arr[trav];
        }
    }
    while (q--) {
        int x,k;
        cin >> x >> k;
        int curnode = x;
        bitset<30> bs(k);
        int j=29;
        while(j>=0) {
            if (bs[j]!=0)
                curnode=dp[curnode][j];
            j--;
        }
        cout << curnode << "\n";
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
