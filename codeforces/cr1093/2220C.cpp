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
	int p,q;
    cin >> p >> q;
    for(int n=1;n<int(1e5) && p+2*q-n>=0;n++) {
        int m = (p+2*q-n)/(2*n+1);
        if ((2*n+1)*m == p+2*q-n && m>0) {
            if (q<=m*n+min(m,n)) {
                cout << n << " " << m << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";


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
