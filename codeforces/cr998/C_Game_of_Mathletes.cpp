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
	int n,k;
    cin >> n >> k;
    vector<int> arr(n+1,0);
    for(int i=0,x;i<n;i++) {
        cin >> x;
        arr[x]++;
    }
    int score = 0;
    for(int i=1;i<=min(n,k-1);i++) {
        if (arr[i]==0)
            continue;
        int temp = k-i;
        if (temp>n || arr[temp]==0) {
            continue;
        }
        if (temp==i) {
            score+=arr[i]/2;
            arr[i]=arr[i]%2;
        } else {
            int mincnt = min(arr[i], arr[temp]);
            score+=mincnt;
            arr[i]-=mincnt, arr[temp]-=mincnt;
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++)
        cnt+=arr[i];
    if (cnt%2==1)
        score--;
    cout << score << "\n";
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
