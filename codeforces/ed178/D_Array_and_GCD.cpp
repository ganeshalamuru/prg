#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;
int N = 66e5l;
vector<int>prime(66e5l,1);
vector<int> primes;
vector<ll>psumprimes;
void findprimes() {
    prime[0]=prime[1]=0;
    for(int i=2;1ll*i*i<N;i++) {
        if (prime[i]==1) {
            for(int j=i*i;j<N;j+=i) {
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<N;i++) {
        if (prime[i]==1) {
            primes.push_back(i);
        }
    }
    psumprimes.resize(primes.size());
    psumprimes[0]=primes[0];
    for(int i=1;i<primes.size();i++) {
        psumprimes[i]=psumprimes[i-1]+primes[i];
    }
}
void solve() {
	int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    ll sum = 0;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        if (psumprimes[n-i-1]<=sum) {
            break;
        } else {
            ans++;
            sum-=arr[i];
        }
    }
    cout << ans << "\n";

}


int main() {
    fast;
    int t = 1;
    cin >> t;
    findprimes();
    while(t--){
    	solve();
    }
    return 0;
}
