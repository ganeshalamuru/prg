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

vector<set<int>> factors(3001);
const int mod = 998244353;
void fillfactors() {
    for(int i=1;i<3001;i++) {
        for(int j=1;j*j<=i;j++) {
            if (i%j==0) {
                factors[i].insert(j);
                factors[i].insert(i/j);
            }
        }
    }
}

void solve() {
	int n,m;
    cin >> n >> m;
    vector<int> arr(n,0);
    for(int &num:arr)
        cin >> num;
    if (arr[0]!=0 && arr[0]!=1) {
        cout << 0 << "\n";
        return;
    }
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    dp[0][1]=1;
    for(int i=1;i<n;i++) {
        if (arr[i]==0) {
            for(int j=1;j<=m;j++) {
                for(int fac:factors[j]) {
                    int qq = j/fac;
                    int nn = fac*(qq-1);
                    dp[i][j]=(dp[i][j]+dp[i-1][nn])%mod;
                }
            }
        } else {
            for(int fac:factors[arr[i]]) {
                int qq = arr[i]/fac;
                int nn = fac*(qq-1);
                dp[i][arr[i]]=(dp[i][arr[i]]+dp[i-1][nn])%mod;
            }
        }
    }
    int ans = 0;
    for(int i=n;i<=m;i++) {
        ans = (ans + dp[n-1][i])%mod;
    }
    cout << ans << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    fillfactors();
    while(t--) {
    	solve();
    }
    
    return 0;
}
