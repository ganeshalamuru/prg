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



void sieve(vector<int> &prime) {
    int n = prime.size();
    for(int i=0;i<n;i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i=2;1ll*i*i<1ll*n;i++) {
        if (prime[i]) {
            for(int j=i*i;j<n;j+=i)
                prime[j] = 0;
        }
    }

}

bool isplandindrome(int num) {
    int tmp = num, num2 = 0;
    while(tmp > 0) {
        num2 = num2*10 + tmp%10;
        tmp/=10;
    }
    return num == num2;
}
vector<int> prime(1e7+1);
void solve() {
    int p,q;
    cin >> p >> q;
    sieve(prime);
    int ans = 0, primes = 0, palindromes = 0;
    for(int i=1;i<1e7+1;i++) {
        primes += prime[i];
        palindromes += isplandindrome(i);
        if (1ll*q*primes <= 1ll*p*palindromes)
            ans = i;
    }
    cout << ans << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
