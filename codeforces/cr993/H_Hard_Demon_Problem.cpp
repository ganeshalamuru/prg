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
	int n,q;
    cin >> n >> q;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cin >> mat[i][j];
    }
    vector<vector<ll>> matssum(n,vector<ll>(n,0));
    vector<vector<ll>> horzsssum(n,vector<ll>(n,0)), verticalsssum(n,vector<ll>(n,0));
    matssum[n-1][n-1]=mat[n-1][n-1];
    for(int j=n-2;j>=0;j--)
        matssum[n-1][j] = matssum[n-1][j+1]+mat[n-1][j];
    for(int i=n-2;i>=0;i--)
        matssum[i][n-1] = matssum[i+1][n-1]+mat[i][n-1];
    for(int i=n-2;i>=0;i--) {
        for(int j=n-2;j>=0;j--) {
            matssum[i][j]=mat[i][j]+ matssum[i+1][j]+matssum[i][j+1]-matssum[i+1][j+1];
        }
    }
    for(int i=n-1;i>=0;i--) {
        vector<ll> ssum(n,0);
        ssum[n-1] = mat[i][n-1];
        for(int j=n-2;j>=0;j--)
            ssum[j] = ssum[j+1]+mat[i][j];
        ll sssum=0;
        for(int j=n-1;j>=0;j--) {
            sssum+=ssum[j];
            horzsssum[i][j]+=sssum;
            if (i+1<n)
                horzsssum[i][j]+=horzsssum[i+1][j];
        }
    }
    for(int j=n-1;j>=0;j--) {
        vector<ll> ssum(n,0);
        ssum[n-1]=mat[n-1][j];
        for(int i=n-2;i>=0;i--)
            ssum[i] = ssum[i+1] + mat[i][j];
        ll sssum = 0;
        for(int i=n-1;i>=0;i--) {
            sssum+=ssum[i];
            verticalsssum[i][j]+=sssum;
            if (j+1<n)
                verticalsssum[i][j]+=verticalsssum[i][j+1];
        } 
    }
    while(q--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--,y1--,x2--,y2--;
        if (x1>x2)
            swap(x1,x2);
        if (y1>y2)
            swap(y1,y2);
        ll ans = 0,hscale=y2-y1+1,vscale = x2-x1+1;
        ans+=horzsssum[x1][y1];
        if (x2+1<n)
            ans-=horzsssum[x2+1][y1];
        if (y2+1<n)
            ans-=horzsssum[x1][y2+1];
        if (x2+1<n && y2+1<n)
            ans+=horzsssum[x2+1][y2+1];
        // remove extra parts of sssum
        if (y2+1<n)
            ans-=hscale*matssum[x1][y2+1];
        if (x2+1<n && y2+1<n)
            ans+=hscale*matssum[x2+1][y2+1];
        if (x1==x2) {
            cout << ans << " ";
            continue; 
        }
        ll vans = 0;
        x1++;
        vans+=verticalsssum[x1][y1];
        if (x2+1<n)
            vans-=verticalsssum[x2+1][y1];
        if (y2+1<n)
            vans-=verticalsssum[x1][y2+1];
        if (x2+1<n && y2+1<n)
            vans+=verticalsssum[x2+1][y2+1];
        //remove extra parts of sssum
        if (x2+1<n)
            vans-=(vscale-1)*(matssum[x2+1][y1]);
        if (x2+1<n && y2+1<n)
            vans+=(vscale-1)*(matssum[x2+1][y2+1]);
        cout << ans+hscale*vans << " ";       
    }
    cout << "\n";

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
