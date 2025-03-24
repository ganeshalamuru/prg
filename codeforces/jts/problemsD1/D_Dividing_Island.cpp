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
	int a,b,c,d,n;
    cin >> a >> b >> c >> d >> n;
    vector<int> area(n);
    for(int &num:area)
        cin >> num;
    int minh = min(b,d), maxh=max(b,d);
    vector<vector<char>> grid(maxh, vector<char>(a+c,'*'));
    for(int i=minh;i<maxh;i++) {
        for(int j=a*(b!=minh);j<a+c*(b!=minh);j++)
            grid[i][j] = '.';
    }
    int row=0,col,dir;
    if (d==minh)
        dir = 1-2*(d&1);
    else 
        dir = 2*(b&1)-1;
    col=(a+c-1)*(dir==-1);
    for(int i=0;i<n;i++) {
        char ch = 'a'+i;
        int ar = area[i];
        while(ar--) {
            grid[row][col]=ch;
            do {
                col+=dir;
                if(col>=a+c)
                    col=a+c-1,row++,dir*=-1;
                else if (col<0)
                    col=0,row++,dir*=-1;
            }
            while(row<maxh && grid[row][col]!='*');
        }
    }
    cout << "YES\n";
    for(int i=0;i<maxh;i++) {
        for(int j=0;j<a+c;j++)
            cout << grid[i][j];
        cout << "\n";
    }
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
