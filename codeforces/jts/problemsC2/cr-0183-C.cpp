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



void print(vector<int> &a) {
    for(int i:a)
        cout << i << " ";
    cout << "\n";
}

void solve(){
	int n;
    cin >> n;
    if (n%2 == 0) {
        cout << -1 << "\n";
        return;
    }
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++)
        a[i]=i,b[i]=(a[i]+1)%n,c[i] = (a[i]+b[i])%n;
    print(a),print(b),print(c);
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
