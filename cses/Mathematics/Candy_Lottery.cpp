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
    
    long double expectation = 0.0l;
    for(int i=1;i<=k;i++) {
        long double prob_max_less_than_i = 1.0l;
        for(int j=1;j<=n;j++) {
            prob_max_less_than_i*=(1.0l*(i-1))/k;
        }
        expectation+=1.0l-prob_max_less_than_i;
    }
    cout << fixed << setprecision(6) << expectation << "\n";


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
