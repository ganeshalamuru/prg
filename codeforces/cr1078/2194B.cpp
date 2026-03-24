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
	int n,x,y;
    cin >> n >> x >> y;
    vector<ll> arr(n);
    ll totmulof5 = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        totmulof5+=arr[i]/x;
    }
    ll maxmoney = LLONG_MIN;
    for(int i=0;i<n;i++) {
        maxmoney = max(maxmoney, arr[i]+(totmulof5-arr[i]/x)*y);
    }
    cout << maxmoney << "\n";



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
