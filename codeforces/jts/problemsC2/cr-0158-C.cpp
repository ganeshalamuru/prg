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
	int n,x;
    cin >> n >> x;
    ll totalballs = 0;
    x--;
    vector<ll> arr(n),prefixmin(n, INT_MAX), suffixmin(n, INT_MAX);
    for(int i=0;i<n;i++)
        cin >> arr[i],totalballs+=arr[i];
    prefixmin[(x+1)%n] = arr[(x+1)%n], suffixmin[x%n] = arr[x%n];
    for(int i=x+2,j=1;j<n;j++,i++)
        prefixmin[i%n] = min(prefixmin[(i-1+n)%n], arr[i%n]);
    for(int i=x-1,j=1;j<n;j++,i--)
        suffixmin[(i+n)%n] = min(suffixmin[(i+1+n)%n],arr[(i+n)%n]);
    vector<ll>res(n);
    for(int i=0;i<n;i++) {
        if (i<x) {
            ll segmentmin = suffixmin[(i+1)%n];
            ll remsegmentmin = prefixmin[(i+n)%n];
            if (segmentmin >= arr[i]+1 && remsegmentmin >= arr[i]) {
                ll tt = 0;
                for(int j=0;j<n;j++) {
                    ll tmp = arr[j]-arr[i];
                    if (j>i&&j<=x)
                        tmp--;
                    tt+=tmp;
                    res[j]=tmp;
                }
                res[i]+=(totalballs-tt);
                break;
            }
        } else if (i==x){
            ll totmin = prefixmin[x];
            if (totmin >=arr[i]) {
                ll tt = 0;
                for(int j=0;j<n;j++) {
                    ll tmp = arr[j]-arr[i];
                    tt+=tmp;
                    res[j]=tmp;
                }
                res[i]+=(totalballs - tt);
                break;
            }
        } else {
            ll segmentmin = prefixmin[i];
            ll remsegmentmin = suffixmin[(i+1)%n];
            if (segmentmin >= arr[i] && remsegmentmin >= arr[i]+1) {
                ll tt =0;
                for(int j=0;j<n;j++) {
                    ll tmp = arr[j]-arr[i];
                    if (!(j>x&&j<=i))
                        tmp--;
                    tt+=tmp;
                    res[j]=tmp;
                }
                res[i]+=(totalballs-tt);
                break;
            }
        }
    }
    for(ll v:res)
        cout << v << " ";
    cout << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
