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




void solve(){
	int n;
    cin >> n;
    vector<vector<int>> mat(n,vector<int>(n,0));
    string s;
    for(int i=0;i<n;i++) {
        cin >> s;
        for(int j=0;j<n;j++)
            mat[i][j] = s[j]-'0';
    }
    vector<vector<int>> rpsump(n,vector<int>(n,0)),rpsumn(n,vector<int>(n,0));
    int steps = 0;
    for(int i=0;i<n;i++) {
        int ops = 0;
        vector<int> curopsrpsump(rpsump[i].begin(), rpsump[i].end());
        vector<int> curopsrpsumn(rpsumn[i].begin(), rpsumn[i].end());
        for(int j=0;j<n;j++) {
            ops+=curopsrpsump[j] + curopsrpsumn[j];
            if ((mat[i][j] == 0 && ops%2==1) || (mat[i][j] == 1 && ops%2==0)) {
                steps++,rpsump[i][j]+=1;
                if (j+1<n) rpsumn[i][j+1]+=-1;
            }
        }
        if (i==n-1)
            break;
        rpsump[i+1][0] = rpsump[i][0];
        for(int j=1;j<n;j++)
            if (rpsump[i][j] > 0)
                rpsump[i+1][j-1] += rpsump[i][j];
        for(int j=0;j<n-1;j++)
            if (rpsumn[i][j] < 0)
                rpsumn[i+1][j+1] += rpsumn[i][j];
    }
    cout << steps << "\n";
}



signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
