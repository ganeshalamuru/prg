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


ll getsum(ll m,vector<int>&arr, vector<int>&pxor) {
    int n = arr.size()-1;
    if (m<1)
        return 0;
    vector<ll> divby2(60);
    for(int i=0;i<60;i++)
        divby2[i]=m/(1ll<<i);
    ll sum = arr[1];
    for(int i=1;i<60;i++) {
        ll totcnt = divby2[i];
        if (i+1<60)
            totcnt-=divby2[i+1];
        ll used = 0,tsum=0;
        for(int j=1;j<=n && (1ll<<i)*j<=m;j+=2) {
            for(const auto &num:{(1ll<<i)*j, (1ll<<i)*j + 1}) {
                ll v=0;
                if (num>m)
                    continue;
                if (num<=n)
                    v=arr[num];
                else {
                    ll temp=num;
                    temp/=2;
                    while(temp>0) {
                        if (temp<=n || temp%2==1) {
                            v^=pxor[min(1ll*n,temp)];
                            break;
                        }
                        v^=pxor[n];
                        temp/=2;
                    }
                }
                tsum+=v;
            }
            used++;
        }
        ll val = pxor[n]*(i%2==1);
        tsum+=(totcnt-used)*2*val;
        if (totcnt-used>0 && (1ll<<i)*(2*(totcnt-1)+1)+1>m)
            tsum-=val;
        sum+=tsum;
        
    }
    return sum;
}

void solve() {
	ll n,l,r;
    cin >> n >> l >> r;
    vector<int> arr(n+1);
    for(int i=0;i<n;i++)
        cin >> arr[i+1];
    vector<int> pxor(n+1,0);
    for(int i=1;i<=n;i++)
        pxor[i]=pxor[i-1]^arr[i];
    if (n%2==0) {
        arr.push_back(pxor[n/2]);
        pxor.push_back(pxor.back()^arr.back());
        n++;
    }
    ll currsum =  getsum(r,arr,pxor), curmlsum = getsum(l-1,arr,pxor);
    cout << currsum-curmlsum << "\n";
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
