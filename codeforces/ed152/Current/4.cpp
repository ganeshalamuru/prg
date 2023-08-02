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




signed main(){
    fast;
    int n;
    cin >> n;
    vector<int> arr(n+2, 0);
    set<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] == 0)
            s.insert(i);
    }
    int i=0,j=1,cost = 0;
    while(j<=n+1) {
        bool twoprsnt = false;
        while(j<=n+1 && arr[j]!= 0) {
            if (arr[j] == 2)
                twoprsnt = true;
            j++;
        }
        int consecNonZeroLen = j-i-1;
        cost += consecNonZeroLen > 0 ? 1 : 0;
        int markingChances = consecNonZeroLen > 0 ? (twoprsnt ? 2 : 1) : 0;
        if (markingChances > 0 && s.find(i) != s.end()) {
            s.erase(i),markingChances--;
        }
        if (markingChances > 0 && s.find(j) != s.end()) {
            s.erase(j),markingChances--;
        }
        i=j;
        j=i+1;
    }
    cout << cost + s.size() << endl;
    return 0;
}
