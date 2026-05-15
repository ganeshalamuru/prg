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

int jsph(int n, int k) {
    if (n==1)
        return 1; 
    if (k<=n/2)
        return 2*k;
    return (n+2*(jsph(n-n/2,k-n/2)-n%2))%(n+1);
}

void solve() {
	int q;
    cin >> q;
    while (q--) {
        int n,k;
        cin >> n >> k;
        cout << jsph(n,k) << "\n";
    }
    


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
