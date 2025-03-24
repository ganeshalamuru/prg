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


bool check(vector<int>& arr, int i) {
    int n = arr.size();
    if (arr[i%n]==1 && arr[(i+1)%n]==5 && arr[(i+2)%n]==4 && arr[(i+3)%n]==3)
        return true;
    return false;
}

void solve() {
	int n,m;
    cin >> n >> m;
    vector<string> mat(n);
    int ans = 0;
    for(auto& row:mat)
        cin >> row;
    for(int z=0;z<min(m+1,n+1)/2;z++) {
        vector<int> arr;
        for(int j=z;j<m-z;j++)
            arr.push_back(mat[z][j]-'0');
        for(int i=z+1;i<n-z;i++)
            arr.push_back(mat[i][m-z-1]-'0');
        for(int j=m-z-2;j>=z;j--)
            arr.push_back(mat[n-z-1][j]-'0');
        for(int i=n-z-2;i>z;i--)
            arr.push_back(mat[i][z]-'0');
        for(int b=0;b<arr.size();b++)
            ans += check(arr, b);
    }
    cout << ans << "\n";
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
