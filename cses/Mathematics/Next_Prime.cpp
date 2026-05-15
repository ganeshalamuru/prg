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

const int M = 1000000+1;
array<int,M> tmpprimes{};
vector<int> primes;
void markprimes() {
    tmpprimes[0]=tmpprimes[1]=-1;
    for(int i=2;i<M;i++) {
        tmpprimes[i]=i;
    }
    for(int i=2;i*i<M;i++) {
        if (tmpprimes[i]==i) {
            for(int j=i*i;j<M;j+=i) {
                if (tmpprimes[j]==j)
                    tmpprimes[j]=i;
            }
        }
    }
    for(int i=2;i<M;i++) {
        if (tmpprimes[i]==i)
            primes.push_back(i);
    }
}

void solve() {
	ll n;
    cin >> n;
    if (n==1) {
        cout << 2 << "\n";
        return;
    }
    vector<int> arr(1001,1);
    for(int j=0;j<int(primes.size()) && primes[j]<n;j++) {
        ll st = n+1;
        if ((n+1)%primes[j] != 0)
            st+=(primes[j])-((n+1)%primes[j]);
        for(ll z=st;z<n+1000;z+=primes[j]) {
            arr[z-n]=0;
        }
    }
    for(int z=1;z<1001;z++) {
        if (arr[z]==0)
            continue;
        ll num = n+z;    
        bool prime = true;
        for(ll i=M;i*i<=num;i++) {
            if (num-i*(num/i)==0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            cout << num << "\n";
            return;
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    markprimes();
    while(t--) {
    	solve();
    }
    
    return 0;
}
