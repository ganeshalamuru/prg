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
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<int> ans = arr;
    int i=0, steps = 0;
    while(i<n) {
        int j=i;
        while(j+1<n && arr[j]!=arr[j+1])
            j++;
        int len = j-i+1;
        if (arr[i] != arr[j]) {
            steps = max(steps, (len-2)/2);
            for(int z=i;z<i+len/2;z++)
                ans[z] = arr[i];
            for(int z=i+len/2;z<=j;z++)
                ans[z] = arr[j];
        } else {
            steps = max(steps, (len-1)/2);
            for(int z=i;z<=j;z++)
                ans[z]=arr[i];
        }
        i=j+1;
    }
    cout << steps << "\n";
    for(int z=0;z<n;z++)
        cout << ans[z] << " ";
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
