#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 5e5+1, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n),narr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<int> expirycnt(5e5+1,0);
    int tcnt = 0,base=0;
    narr[0]=arr[0];
    expirycnt[narr[0]]++;
    tcnt++;
    for(int i=1;i<n;i++) {
        tcnt-=expirycnt[base];
        narr[i]=arr[i]+tcnt;
        base++;
        tcnt++;
        expirycnt[min((int)expirycnt.size()-1,base+narr[i])]++;;
    }
    for(int i=0;i<n;i++) {
        cout << max(0,narr[i]-(n-1-i)) << " ";
    }
    cout << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
