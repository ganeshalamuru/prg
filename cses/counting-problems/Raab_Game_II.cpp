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


const int MOD = 1e9+7;
const int N = 5000 + 1;

vector<int> fact(N);

int madd(ll a, ll b) {
    a%=MOD,b%=MOD;
    return int((a+b)%MOD);
}
int mmul(ll a, ll b) {
    a%=MOD,b%=MOD;
    return int((a*b)%MOD);
}

void pre_calculate(vector<vector<int>> &dp,vector<vector<int>> &nCr) {
    fact[0]=1;
    for(int i=1;i<N;i++) {
        fact[i]=mmul(i,fact[i-1]);
    }

    for(int i=0;i<N;i++) {
        nCr[i][0]=1;
        for(int j=1;j<=i;j++) {
            nCr[i][j]=madd(nCr[i-1][j-1],nCr[i-1][j]);
        }
    }

    // dp[n][k] = n-1*dp[n-2][k-1] + k*dp[n-1][k] + (n-k)*dp[n-1][k-1]
    dp[0][0]=1;
    for(int i=2;i<N;i++)
        dp[i][1]=1;
    for(int i=2;i<N;i++) {
        for(int j=2;j<N;j++) {
            dp[i][j]=madd(mmul(dp[i-2][j-1],i-1),madd(mmul(j,dp[i-1][j]),mmul(i-j,dp[i-1][j-1])));
        }
    }
}


void solve(int n, int a, int b,vector<vector<int>> &dp,vector<vector<int>> &nCr) {

    if (a+b > n) {
        cout << 0 << "\n";
        return;
    }
    int draws = n - (a+b);

    cout << mmul(nCr[n][draws],mmul(dp[n-draws][a],fact[n])) << "\n";

}

void solve2(int n,int a, int b) {
    if (a+b > n) {
        cout << 0 << "\n";
        return;
    }
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        arr[i]=i;
    }
    int ans = 0;
    do {
        int tmpa =0, tmpb = 0;
        for(int i=0;i<n;i++) {
            if (i>arr[i]) {
                tmpa++;
            } else if (i<arr[i]) {
                tmpb++;
            }
        }
        // cout << "perm\n";
        // for(int i=0;i<n;i++) {
        //     cout << i+1 << " " << arr[i]+1 << "\n";
        // }
        // cout << "tmpa " << tmpa << " " << tmpb << "\n";
        if (tmpa==a && tmpb==b) {
            ans = madd(ans,1);
        }

    } while(next_permutation(all(arr)));
    cout << mmul(ans,fact[n]) << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    vector<vector<int>> dp(N,vector<int>(N)),nCr(N,vector<int>(N));
    pre_calculate(dp,nCr);
    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;
        // cout << "solve \n";
    	solve(n,a,b,dp,nCr);
        // cout << "solve2 \n";
        // solve2(n,a,b);
    }
    
    return 0;
}
