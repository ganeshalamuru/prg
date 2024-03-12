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
	int n,k;
    cin >> n >> k;
    vector<int>a(n),freq(1e5+1,0);
    for(int&i:a)
        cin >> i;
    int i=0,j=0,uniq = 0;
    ll goodcnt = 0;
    while(j<n) {
        freq[a[j]]++;
        if (freq[a[j]]==1)
            uniq++;
        while(i<=j && uniq > k) {
            freq[a[i]]--;
            if (freq[a[i]]==0)
                uniq--;
            i++;
        }
        goodcnt+=(j-i+1);
        j++;
    }
    cout << goodcnt << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
