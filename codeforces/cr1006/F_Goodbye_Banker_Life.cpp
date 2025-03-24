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



int numtows(int i) {
    int cnt = 0,tw=2;
    while((i/tw)>0) {
        cnt+=(i/tw);
        tw*=2;
    }
    return cnt;
} 

void solve() {
	int n,k;
    cin >> n >> k;
    if (n==1) {
        cout << k << "\n";
        return;
    }
    vector<int> ans{k};
    n--;
    int j=1;
    while(j<n) {
        if (numtows(n)>numtows(j)+numtows(n-j))
            ans.push_back(0);
        else
            ans.push_back(k);
        j++;
    }
    ans.push_back(k);
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    cout << "\n";
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
