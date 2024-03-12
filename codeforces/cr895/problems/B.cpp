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


bool possible(vector<int>& d,vector<int> s, int k) {
    for(int i=0;i<d.size();i++) {
        if (k<=d[i])
            continue;
        if ((k-d[i])*2>=s[i])
            return false;
    }
    return true;
}


void solve(){
	int n;
    cin >> n;
    vector<int> d(n),s(n);
    for(int i=0;i<n;i++)
        cin >> d[i] >> s[i];
    int l=1,r=1000;
    while(l<r) {
        int mid = l + (r-l+1)/2;
        if (possible(d,s,mid)) {
            l=mid;
        } else {
            r=mid-1;
        }
    }
    cout << l << "\n";
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
