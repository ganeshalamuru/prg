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


void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> brd(n),color(n);
    vector<int> rowUcnt(n,0), colLcnt(m,0);
    for(int i=0;i<n;i++)
        cin >> brd[i],color[i]=brd[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if (brd[i][j]=='L')
                colLcnt[j]++;
            else if (brd[i][j]=='U')
                rowUcnt[i]++;
    for(int i=0;i<n;i++) {
        if (rowUcnt[i]%2) {
            cout << "-1\n";
            return;
        }
    }
    for(int j=0;j<m;j++) {
        if (colLcnt[j]%2) {
            cout << "-1\n";
            return;
        }
    }
    // fill vertical
    for(int i=0;i<n;i++) {
        if (rowUcnt[i]==0)
            continue;
        int half = rowUcnt[i] / 2;
        for(int j=0;j<m;j++) {
            if (brd[i][j]=='U') {
                char ch1 = half > 0 ? 'W' : 'B';
                char ch2 = ch1 == 'W' ? 'B':'W';
                color[i][j] = ch1, color[i+1][j] = ch2;
                half--;
            }
        }
    }
    // fill horizontal
    for(int j=0;j<m;j++) {
        if (colLcnt[j]==0)
            continue;
        int half = colLcnt[j] / 2;
        for(int i=0;i<n;i++) {
            if (brd[i][j]=='L') {
                char ch1 = half > 0 ? 'W' : 'B';
                char ch2 = ch1 == 'W' ? 'B':'W';
                color[i][j] = ch1, color[i][j+1] = ch2;
                half--;
            }
                
        }
    }
    for(string &s:color)
        cout << s << "\n";

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
