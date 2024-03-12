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



bool valid(vector<int> &a, int max) {
    int i=a.size()-1;
    while(i>=0 && max>0) {
        if (a[i]==max) {
            max--;
        }
        i--,max--;
    }
    return i<0 && max>=0;
}

void solve(){
	int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int j=n;
    while(!valid(a, j)) {
        j++;
    }
    cout << j << "\n";
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
