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
	int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int x=0,y=0;
    vector<vector<int>> places(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        if (s[i]=='N')
            y++;
        else if (s[i]=='E')
            x++;
        else if (s[i]=='S')
            y--;
        else
            x--;
        places[i][0]=x,places[i][1]=y;
    }
    int endx=places[n-1][0], endy=places[n-1][1];
    for(int i=0;i<n;i++) {
        if (endx==0 && endy==0) {
            if (a==places[i][0] && b==places[i][1]) {
                cout << "YES\n";
                return;
            }
        } else if (endx !=0 && endy==0) {
            if ((abs(a-places[i][0])%abs(endx))==0 
                    && ((endx<0 && (a-places[i][0]<=0)) || (endx>0 &&(a-places[i][0])>=0)) 
                    && b==places[i][1]) {
                        cout << "YES\n";
                        return;
            }
        } else if (endx == 0 && endy!=0) {
            if ((abs(b-places[i][1])%abs(endy))==0 
                    && ((endy<0 && (b-places[i][1]<=0)) || (endy>0 &&(b-places[i][1])>=0)) 
                    && a==places[i][0]) {
                        cout << "YES\n";
                        return;
            }
        } else {
            if ((abs(a-places[i][0])%abs(endx))==0 
                    && ((endx<0 && (a-places[i][0]<=0)) || (endx>0 &&(a-places[i][0])>=0)) 
                    && (abs(b-places[i][1])%abs(endy))==0 
                    && ((endy<0 && (b-places[i][1]<=0)) || (endy>0 &&(b-places[i][1])>=0)) 
                    && (abs(a-places[i][0])/abs(endx)==(abs(b-places[i][1])/abs(endy)))) {
                        cout << "YES\n";
                        return;
            }
        }
    }
    cout << "NO\n";
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
