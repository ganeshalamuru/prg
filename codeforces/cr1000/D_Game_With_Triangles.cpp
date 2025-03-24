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
	int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> a2,b2;
    for(int i=0,j=a.size()-1;i<j;i++,j--)
        a2.push_back(a[j]-a[i]);
    for(int i=0,j=b.size()-1;i<j;i++,j--)
        b2.push_back(b[j]-b[i]);
    vector<ll> res;
    int i=0,j=0,flag=0;
    ll cursum = 0;
    while(true) {
        pair<ll,ll> ans = {LLONG_MIN, -1};
        // if base on y=0 is chosen
        if (m-i-2*j>0 && n-j-2*i>1 && ans.F < cursum+a2[i])
            ans = {cursum+a2[i], 0};
        // if base on y=2 is chosen
        if (m-i-2*j>1 && n-j-2*i>0 && ans.F < cursum+b2[j])
            ans = {cursum+b2[j], 2};
        if (ans.F!=LLONG_MIN) {
            flag=0;
            res.push_back(ans.F);
            cursum=ans.F;
            if (ans.S == 0)
                i++;
            else
                j++;
            continue;
        }
        if (flag)
            break;
        // remove base from y=0 and add base from y=2
        if (i>0 && m-(i-1)-2*j>1 && n-j-2*(i-1)>0 && ans.F < cursum-a2[i-1]+b2[j])
            ans = {cursum-a2[i-1]+b2[j], 0};
        // remove base from y=2 and add base from y=0
        if (j>0 && n-(j-1)-2*i>1 && m-i-2*(j-1)>0 && ans.F < cursum-b2[j-1]+a2[i])
            ans = {cursum-b2[j-1]+a2[i], 2};
        if (ans.F==LLONG_MIN)
            break;
        cursum=ans.F;
        // next selection of base should be compulsory
        flag=1;
        if (ans.S==0)
            i--,j++;
        else
            i++,j--;
    }
    cout << res.size() << "\n";
    for(ll &num:res)
        cout << num << " ";
    cout << "\n";
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
