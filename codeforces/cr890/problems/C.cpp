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


bool possible(int target, vector<int>& arr, int maxmoves) {

    for(int i=0;i<arr.size();i++) {
        int movesleft = maxmoves;
        int curTarget = target;
        for(int j=i;j<arr.size() && movesleft>=0;j++) {
            if (curTarget <= arr[j]) {
                return true;
            } else if (movesleft == 0) {
                break;    
            } else {
                int diff = curTarget - arr[j];
                movesleft -= diff;
                curTarget--;
            }
        }
    }
    return false;
}


void solve(){
	int n,k,maxele = INT_MIN;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i],maxele = max(maxele, arr[i]);
    int l = maxele, r = maxele + n - 1;
    while(l<r) {
        int mid = l + (r-l+1) / 2;
        if (possible(mid, arr, k)) {
            l=mid;
        } else {
            r=mid-1;
        }
    }
    cout << l << "\n";
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
