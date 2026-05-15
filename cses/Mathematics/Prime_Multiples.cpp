#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;



void solve() {
	ll n,k;
    cin >> n >> k;
    array<ll,20> primes{};
    for(int i=0;i<k;i++)
        cin >> primes[i];
    ll ans = 0;
    for(int i=1;i<(1<<k);i++) {
        ll prod = 1,nump=0;
        bool prodexceedsn = false;
        for(int j=0;j<k;j++) {
            if ((i>>j)&1) {
                if (prod > n/primes[j]) {
                    prodexceedsn = true;
                    break;
                } else {
                    prod*=primes[j];
                    nump++;
                }
            }
        }
        if (prodexceedsn)
            continue;
        if (nump%2)
            ans+=n/prod;
        else
            ans-=n/prod;
    }
    cout << ans << "\n";



}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
