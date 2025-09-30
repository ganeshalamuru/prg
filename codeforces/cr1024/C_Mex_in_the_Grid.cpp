#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<vector<int>> ans(n+1,vector<int>(n+1,-1));
    vector<vector<int>> gridfreq(n+1,vector<int>(n+1,0));
    vector<vector<int>> vis(n+1,vector<int>(n+1,0));
    set<vector<int>,greater<vector<int>>>ss;
    ss.insert({0,n/2+n%2,n/2+n%2});
    vis[n/2+n%2][n/2+n%2]=1;
    int val = 0;
    while(!ss.empty()) {
        auto itr = ss.begin();
        auto tp = *itr;
        ss.erase(itr);
        ans[tp[1]][tp[2]]=val;
        val++;
        for(int i=max(1,tp[1]-1);i<=min(n,tp[1]+1);i++) {
            for(int j=max(1,tp[2]-1);j<=min(n,tp[2]+1);j++) {
                if (vis[i][j]!=0) {
                    if (ans[i][j]==-1) {
                        ss.erase({gridfreq[i][j],i,j});
                        if (i==tp[1]||j==tp[2])
                            gridfreq[i][j]+=2*val;
                        else
                            gridfreq[i][j]+=val;
                        ss.insert({gridfreq[i][j],i,j});
                    }
                } else {
                    vis[i][j]=1;
                    if (i==tp[1]||j==tp[2])
                        gridfreq[i][j]+=2*val;
                    else
                        gridfreq[i][j]+=val;
                    ss.insert({gridfreq[i][j],i,j});
                }
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
