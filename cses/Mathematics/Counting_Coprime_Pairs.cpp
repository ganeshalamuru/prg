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

const int M = 1e6+1;
array<int,M> mobius{},freq{},nummultiples{},is_composite{};
vector<int> primes;

void calculatemobius() {
    mobius[1]=1;
    for(int j=2;j<M;j++) {
        if (!is_composite[j]) {
            primes.push_back(j);
            mobius[j]=-1;
        }
        for(int i=0;i<int(primes.size()) && j*primes[i]<M;i++) {
            is_composite[j*primes[i]]=1;
            if (j%primes[i]==0)
                break;
            mobius[j*primes[i]]=mobius[j]*mobius[primes[i]];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        freq[x]++;
    }
    nummultiples[1]=n;
    for(int i=2;i<M;i++) {
        for(int j=i;j<M;j+=i) {
            nummultiples[i]+=freq[j];
        }
    }
    calculatemobius();
    ll ans = 0;
    for(int i=1;i<M;i++) {
        ans += 1ll*mobius[i]*((1ll*nummultiples[i]*(nummultiples[i] - 1))/2);
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
