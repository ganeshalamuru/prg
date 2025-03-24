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
    int n;
    cin >> n;
    vector<vector<int>> arr(n+1);
    for(int i=0,x;i<n;i++)
        cin >> x,arr[x].push_back(i+1);
    vector<ll> f(n+1,0);
    for(int i=0;i<=n;i++) {
        ll sum=0, prev = 0;
        arr[i].push_back(n+1);
        for(int &ind:arr[i]) {
            int len = ind-prev;
            sum+=(1ll*len*(len-1))/2;
            prev = ind;
        }
        arr[i].pop_back();
        f[i]=sum;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        vector<int> temp;
        int j=0,z=0;
        while(j<arr[i-1].size()&& z<arr[i].size()) {
            if (arr[i-1][j]<arr[i][z])
                temp.push_back(arr[i-1][j]),j++;
            else
                temp.push_back(arr[i][z]),z++;
        }
        while(j<arr[i-1].size())
            temp.push_back(arr[i-1][j]),j++;
        while(z<arr[i].size())
            temp.push_back(arr[i][z]),z++;
        temp.push_back(n+1);
        ll sum=0, prev = 0;
        for(int &ind:temp) {
            int len = ind-prev;
            sum+=(1ll*len*(len-1))/2;
            prev = ind;
        }
        ans+=f[i-1]-sum;
    }
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
