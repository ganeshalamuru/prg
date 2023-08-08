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
	int n,a;
    cin >> n;
    int m = (n*(n-1)) / 2;
    map<int, int> mp;
    for (int i =0 ; i<m;i++)
        cin >> a,mp[a]++;
    int numElements = n;
    vector<int> arr;
    for(auto keyval: mp) {
        int numcmps = keyval.second;
        while(numcmps>0) {
            numcmps-=(numElements-1);
            arr.push_back(keyval.first);
            numElements--;
        }
    }
    if (numElements>0) {
        arr.push_back(arr.back());
    }
    for(int i = 0;i < arr.size();i++) {
        cout << arr[i] << " ";
    }
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
