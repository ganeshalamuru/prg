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


vector<int>bit;

void update(int i,int val) {
    while(i<bit.size()) {
        bit[i]+=val;
        i+=i-(i&(i-1));
    }
}

void initbit(int n) {
    bit.resize(n+1,0);
    for(int i=1;i<=n;i++)
        update(i,1);
}

int findsum(int i) {
    int sum = 0;
    while(i>0) {
        sum+=bit[i];
        i=(i&(i-1));
    }
    return sum;
}


int findkth(int st, int k) {
    int tot = findsum(bit.size()-1);
    int req = k%tot+1;
    int sumst1 = findsum(st-1);
    if (req<=tot-sumst1) {
        int l=st,r=bit.size()-1;
        while(l<r) {
            int mid = l+(r-l)/2;
            if (findsum(mid)-sumst1<req)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    } else {
        req-=(tot-sumst1);
        int l=1,r=st-1;
        while(l<r) {
            int mid = l+(r-l)/2;
            if (findsum(mid)<req)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
}



void solve() {
	int n,k;
    cin >> n >> k;
    initbit(n);
    vector<int>ans(n);
    int st=1;
    for(int i=0;i<n;i++) {
        ans[i]=findkth(st,k);
        update(ans[i],-1);
        st=ans[i];
    }
    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
