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
    cin>> n >> m;
    if (m==1) {
        cout << "YES\n";
        for(int x=1;x<=2*n;x++) {
            for(int y=1;y<=m;y++) {
                cout << 1 << " ";
            }
            cout << "\n";
        }
        return;
    }
    if (m>=2*n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<vector<int>> adj(m,vector<int>(2*n));
    vector<int> temp(2*n);
    for(int i=0,val=1;i<2*n;i+=2,val++) {
        temp[i]=val;
        temp[i+1]=val;
    }
    int k=0,i=0,j=0;
    while(i<n &&k<m) {
        adj[k] = temp;
        rotate(temp.begin(), temp.begin()+2, temp.end());
        i++,k++;
    }
    vector<int> temp2(2*n);
    for(int z=0,val1=1,val2=n-1;z<2*n;z+=2,val1++,val2=(val2+1)%n) {
        temp2[z]=val1,temp2[z+1]=val2+1;
    }
    while(j<n-1 && k<m) {
        adj[k]=temp2;
        rotate(temp2.begin(), temp2.begin()+2, temp2.end());
        j++,k++;
    }
    i=0;
    for(;i<2*n;i++) {
        j=0;
        for(;j<m;j++) {
            cout << adj[j][i] << " ";
        }
        cout << "\n";
    }

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
