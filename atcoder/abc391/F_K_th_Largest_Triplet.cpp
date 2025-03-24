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



ll calcval(ll a, ll b ,ll c) {
    return a*b+b*c+c*a;
}

void solve() {
	int n,k;
    cin >> n >> k;
    vector<vector<int>> arr(3,vector<int>(n));
    for(int i=0;i<3;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<3;i++)
        sort(arr[i].begin(), arr[i].end());
    set<vector<ll>,greater<vector<ll>>> ss;
    ss.insert({calcval(arr[0][n-1],arr[1][n-1],arr[2][n-1]),n-1,n-1,n-1});
    int kthlargest = 1;
    while(kthlargest<k) {
        auto pp = *ss.begin();
        ss.erase(ss.begin());
        if (pp[1]-1>=0)
            ss.insert({calcval(arr[0][pp[1]-1],arr[1][pp[2]],arr[2][pp[3]]),pp[1]-1,pp[2],pp[3]});
        if (pp[2]-1>=0)
            ss.insert({calcval(arr[0][pp[1]],arr[1][pp[2]-1],arr[2][pp[3]]),pp[1],pp[2]-1,pp[3]});
        if (pp[3]-1>=0)
            ss.insert({calcval(arr[0][pp[1]],arr[1][pp[2]],arr[2][pp[3]-1]),pp[1],pp[2],pp[3]-1});
        kthlargest++;
    }
    cout << (*ss.begin())[0] << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
