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
    vector<int> arr(n);
    for(int& num:arr)
        cin >> num;
    auto startItr = min_element(arr.begin(), arr.end());
    int startInd = startItr - arr.begin();
    if (startItr == arr.begin()) {
        auto tmp = find_if(arr.rbegin(), arr.rend(), [&startItr](int num){return num!=*startItr;});
        if (tmp == arr.rend()) {
            cout << 0 << "\n";
            return;
        }
        if (tmp != arr.rbegin())
            startInd =  n-1 - ((tmp - arr.rbegin()) - 1);
    }

    for(int j=startInd+1;j<startInd+n;j++) {
        if (arr[(j-1)%n]<=arr[j%n])
            continue;
        else {
            cout << -1 << "\n";
            return;
        }
    }
    cout << (n - startInd)%n << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
