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
	int n,m,a,b;
    cin >> n >> m >> a >> b;
    if (__gcd(n,a)!=1 || __gcd(b,m)!=1) {
        cout << "NO\n";
        return;
    }
    if (__gcd(n,m)<=2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
