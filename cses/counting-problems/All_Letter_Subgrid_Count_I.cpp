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
    int dis[2][26][3001];
    for(int z=0;z<2;z++) {
        for(int x=0;x<k;x++) {
            for(int y=0;y<n+1;y++) {
                dis[z][x][y]=INT_MAX;
            }
        }
    }
    int vclosest[26][3001];
    for(int x=0;x<k;x++) {
        for(int y=0;y<n+1;y++) {
            vclosest[x][y]=INT_MIN;
        }
    }
    ll ans = 0,disind=1;
    for(int i=1;i<=n;i++,disind^=1) {
        array<int,3001> dp{};   
        for(int z=0;z<k;z++) {
            int closestxchar = INT_MAX;
            for(int j=1;j<=n;j++) {
                if (grid[i-1][j-1]==char('A'+z)) {
                    dis[disind][z][j] = 1;
                    vclosest[z][j]=max(vclosest[z][j],i);
                    closestxchar=1;
                } else {
                    if (vclosest[z][j]!=INT_MIN)
                        dis[disind][z][j]=i-vclosest[z][j]+1;
                    else
                        dis[disind][z][j]=INT_MAX;
                    if (closestxchar!=INT_MAX)
                        dis[disind][z][j]=min(dis[disind][z][j],closestxchar+1);
                    if (dis[disind^1][z][j-1]!=INT_MAX)
                        dis[disind][z][j]=min(dis[disind][z][j],dis[disind^1][z][j-1]+1);
                    if (closestxchar!=INT_MAX)
                        closestxchar++;
                }
                dp[j]=max(dp[j],dis[disind][z][j]);
            }
        }
        for(int j=1;j<=n;j++) {
            cout << dp[j] << " ";
            if (dp[j]>min(i,j))
                continue;
            ans+=max(min(i,j)-dp[j]+1,0);
        }
        cout << "\n";

    }
    cout << ans << "\n";
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