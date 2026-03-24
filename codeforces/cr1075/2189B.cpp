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
	ll n,x;
    cin >> n >> x;
    vector<array<ll,3>>arr(n);
    ll maxstart = 0,maxdelta = LLONG_MIN;
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        maxstart +=(arr[i][1]-1)*arr[i][0];
        maxdelta = max(maxdelta,arr[i][1]*arr[i][0]-arr[i][2]);
    }
    if (maxstart>=x) {
        cout << 0 << "\n";
        return;
    }
    if (maxdelta<=0) {
        cout << -1 << "\n";
        return;
    }
    ll diff = x - maxstart;
    cout << (diff+maxdelta-1)/maxdelta << "\n";
    

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
