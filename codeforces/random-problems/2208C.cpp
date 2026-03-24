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
	int n;
    cin >> n;
    vector<int> c(n),p(n);
    for(int i=0;i<n;i++) {
        cin >> c[i] >> p[i];
    } 
    vector<double> dp(n);
    dp[n-1] = c[n-1];
    for(int i=n-2;i>=0;i--) {
        dp[i] = max(dp[i+1],c[i]+(1.0-p[i]/100.0)*dp[i+1]);
    }
    cout << setprecision(8) << fixed << dp[0] << "\n";


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
