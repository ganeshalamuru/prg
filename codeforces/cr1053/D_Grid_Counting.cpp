#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll mod = 998244353;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

int madd (ll a, ll b){
    a = a%mod, b = b%mod;
	return (0ll + a + b)%mod;
}
int msub (ll a, ll b){
    a = a%mod, b = b%mod;
	return (0ll + a - b + mod)%mod;
}
int mmul (ll a, ll b){
    a = a%mod, b = b%mod;
	return (1ll * a * b)%mod;
}
int minv (ll a){
    a = a%mod;
	return powe(a, mod-2);
}
int mdiv (ll a, ll b){
	return mmul(a, minv(b));
}

int fac[(int)2e5l+1];

int ncr(int n, int r){
    if (r < 0 || n < 0 || r > n)
        return 0;
    return mdiv(fac[n], mmul(fac[r], fac[n-r]));
}

void pre(){
    fac[0] = 1;
    for (int i = 1; i < (int)2e5l+1; i ++){
        fac[i] = mmul(i, fac[i-1]);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    //ll sum = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        //sum+=arr[i];
    }
    int i=n/2 - (n%2==0);
    ll ans = 1;
    int available = 1 + (n%2==0);
    for(int j=i+1;j<n;j++) {
        if (arr[j]>0) {
            cout << 0 << "\n";
            return;
        }
    }
    while(i>=0) {
        if (arr[i]>available) {
            cout << 0 << "\n";
            return;
        } else {
            ans=mmul(ans,ncr(available,arr[i]));
            available-=arr[i];
            if (i>0)
                available+=2;
        }
        i--;
    }
    if (available>0) {
        cout << 0 << "\n";
        return;
    }
    cout << ans << "\n";


}


int main() {
    fast;
    int t = 1;
    cin >> t;
    pre();
    while(t--){
    	solve();
    }
    return 0;
}
