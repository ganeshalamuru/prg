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


vector<int> bit;
void update(int i, int val) {
    while(i<bit.size()) {
        bit[i]+=val;
        i+=i-(i&(i-1));
    }
}

int prefixsum(int i) {
    int ss =0;
    while(i>0) {
        ss+=bit[i];
        i=(i&(i-1));
    }
    return ss;
}

int findindexofpsum(int psum) {
    int l=1,r=bit.size()-1;
    while(l<r) {
        int mid = l + (r-l)/2;
        int ppsum = prefixsum(mid); 
        if (ppsum>=psum)
            r=mid;
        else
            l=mid+1;
    }
    if (prefixsum(l)==psum)
        return l;
    else
        return -1;
}


void solve() {
    int n;
    cin >> n;
    bit.resize(n+1);
    for(int i=1;i<=n;i++)
        update(i,1);
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    vector<int> ans(n+1);
    for(int i=n;i>=1;i--) {
        int ind = findindexofpsum(arr[i]);
        ans[ind]=i;
        update(ind,-1);
    }
    for(int i=1;i<=n;i++)
        cout << ans[i] << " ";
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
