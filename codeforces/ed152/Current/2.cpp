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
	long n, k, a;
    cin >> n >> k;
    vector<pair<long, long>> arr2(n);
    for (int i=0;i<n;i++) {
        cin >> a;
        arr2[i] = {a%k, i+1};
        if (arr2[i].first == 0)
            arr2[i].first = k;
    }
    sort(arr2.begin(), arr2.end(), [](pair<long, long> ap, pair<long, long> bp) {if (ap.first == bp.first) return ap.second < bp.second; 
        else return ap.first > bp.first;});
    for (int i=0;i<n;i++)
        cout << arr2[i].second << " ";
    cout << endl;
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
