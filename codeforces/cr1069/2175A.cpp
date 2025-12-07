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
    vector<ll> a(n);
    set<ll> ss;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        ss.insert(a[i]);
    }
    sort(all(a));
    ll numd = ll(ss.size());
    for(int i=0;i<n;i++) {
        if (a[i]<numd)
            continue;
        cout << a[i] << "\n";
        break;
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
