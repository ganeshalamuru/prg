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
	int n,k;
    cin >> n >> k;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }
    if (n==1) {
        if (k%2 == 1) {
            cout << max(a[0]+b[0],a[0]-b[0]) << "\n";
        } else {
            cout << a[0] << "\n";
        }
        return;
    }
    vector<ll> dp(n,LLONG_MIN);
    dp[0]=a[0];
    for(int i=1;i<n;i++) {
        dp[i]=max(a[i],a[i]+dp[i-1]);
    }
    if (k%2 == 0) {
        cout << *max_element(all(dp)) << "\n";
        return;
    }
    vector<ll> dpr(n,LLONG_MIN);
    dpr[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--) {
        dpr[i]=max(a[i],a[i]+dpr[i+1]);
    }
    ll maxsum = max(a[0]+b[0],a[0]-b[0])+max(0ll,dpr[1]);
    for(int i=1;i<n;i++) {
        ll tmpmaxsum = max(max(a[i]+b[i],a[i]+b[i]+dp[i-1]),max(a[i]-b[i],a[i]-b[i]+dp[i-1]));
        if (i+1<n) {
            tmpmaxsum+=max(0ll,dpr[i+1]);
        }
        maxsum = max(maxsum, tmpmaxsum);
    }
    cout << maxsum << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
