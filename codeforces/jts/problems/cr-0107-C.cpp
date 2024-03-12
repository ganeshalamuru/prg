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


const int MAXN = 20000001;
vector<int> prime(MAXN,1);
void sieve() {
    prime[0] = prime[1] = 0;
    for(int i=2;i*i<MAXN;i++)
        if (prime[i])
            for(int j=i*i; j<MAXN; j+=i)
                prime[j]=0;

}


void solve(){
	ll q,oq;
    cin >> q;
    oq=q;
    if (q==1) {
        cout << 1 << "\n" << 0 << "\n";
        return;
    }
    sieve();
    ll p1=1,p2=1;
    for(int i=2;i<MAXN;i++) {
        if (prime[i])
            if (q%i == 0) {
                p1 = i;
                q/=i;
                break;
            }
    }
    for(int i=2;i<MAXN;i++) {
        if (prime[i])
            if (q%i == 0) {
                p2 = i;
                q/=i;
                break;
            }
    }
    if (oq < MAXN) {
        if (prime[oq])
            cout << "1\n0\n";
        else if (oq==p1*p2)
            cout << "2\n";
        else
            cout << "1\n" << p1*p2 << "\n";
    } else {
        if (oq==q) {
            cout << "1\n0\n";
        } else if (oq==p1*p2 || (oq!=q && (p1==1||p2==1)))
            cout << "2\n";
        else
            cout << "1\n" << p1*p2 << "\n";
    }
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
