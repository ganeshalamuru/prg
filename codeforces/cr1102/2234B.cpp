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
	ll n;
    cin >> n;
    ll rem = n%12;
    if (rem<=9 || rem==11) {
        cout << rem << " " << n-rem << "\n";
    } else if(n==10) {
        cout << -1 << "\n";
    } else {
        cout << 22 << " " << n-22 << "\n";
    }



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
