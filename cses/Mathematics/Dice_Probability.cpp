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
	int n,a,b;
    cin >> n >> a >> b;
    vector<long double> dp(6*n+1);
    dp[0]=1.0l;
    for(int j=1;j<=n;j++) {
        for(int i=6*j;i>=0;i--) {
            dp[i]=0.0l;
            for(int z=1;z<=6;z++) {
                if (i-z>=0)
                    dp[i]+=(1.0l/6.0l)*dp[i-z];
            }
        }
    }
    cout.precision(6);
    cout << fixed << accumulate(dp.begin()+a,dp.begin()+b+1,0.0l) << "\n";

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
