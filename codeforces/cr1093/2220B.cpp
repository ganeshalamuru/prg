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
	ll n,m;
    cin >> n >> m;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int j=0;
    while (j<n) {
        ll val=arr[j],times=0;
        while (j<n && val == arr[j]) {
            times++,j++;
        }
        if (times>=m) {
            cout << "NO\n";
            return;
        }
    }
    
    
    cout << "YES\n";

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
