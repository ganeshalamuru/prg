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
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i:arr)
        cin >> i;
    sort(arr.rbegin(), arr.rend());
    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1] + arr[i];
    ll maxbeauty = 0;
    int matrixsz = n;
    while (matrixsz>0)
    {
        int num = n / matrixsz;
        maxbeauty += prefix[num-1];
        matrixsz/=4;
    }
    cout << maxbeauty << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
