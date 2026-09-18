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


const ll MOD = 1e9+7;

int madd(ll a, ll b) {
    a%=MOD,b%=MOD;
    return int((a+b)%MOD);
}
int mmul(ll a, ll b) {
    a%=MOD,b%=MOD;
    return int((a*b)%MOD);
}


void solve() {
	string s;
    cin >> s;
    int n = int(s.size());
    if (n%2 == 1) {
        cout << 0 << "\n";
        return;
    }
    vector<vector<int>> nCr(n+1,vector<int>(n+1));
    for(int i=0;i<n+1;i++) {
        nCr[i][0]=1;
        for(int j=1;j<=i;j++) {
            nCr[i][j]=madd(nCr[i-1][j-1],nCr[i-1][j]);
        }
    }
    // cout << "before dp\n" << flush;
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=1;i<n+1;i++) {
        dp[i-1][i]=1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=i-1;j>=1;j-=2) {
            for(int z=i-1;z>=j;z--) {
                // cout << "i j z " << i << " " << j << " " << z << "\n" << flush; 
                if (s[z-1]==s[i-1]) {
                    int tmpans = mmul(nCr[(i-j+1)/2][((z-1)-j+1)/2], mmul(dp[i-1][z+1],dp[z-1][j]));    
                    // cout << "tmpans " << tmpans << "\n";
                    dp[i][j]=madd(dp[i][j],tmpans);
                }
            }
        }
    }
    cout << dp[n][1] << "\n";

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
