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
    ll s;
    cin >> n >> s;
    vector<int>a(n);
    for(int&i :a)
        cin >> i;
    int i=0,j=0,shortest=INT_MAX;
    ll cursum = 0;
    while(j<n) {
        cursum+=a[j];
        while(i<=j && cursum-a[i]>=s) cursum-=a[i],i++;
        if (cursum>=s)
            shortest = min(shortest, j-i+1);
        j++;
    }
    if (shortest==INT_MAX)
        cout << -1 << "\n";
    else
        cout << shortest << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
