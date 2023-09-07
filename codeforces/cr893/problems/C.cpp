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
	long long n;
    cin >> n;
    vector<long long> arr(n+1, 0);
    vector<long long> res;
    res.push_back(1);
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) {
            long long num = i;
            while(num <= n) {
                res.push_back(num);
                arr[num] = 1;
                num*=2;
            }
        }
    }
    for (int num : res)
        cout << num << " ";
    cout << "\n";
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
