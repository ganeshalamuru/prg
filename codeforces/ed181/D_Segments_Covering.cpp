#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 998244353;
int mmul(int a, int b) {
    return(1ll*a*b)%mod;
}
int madd(int a, int b) {
    return(a+b)%mod;
}
int mpow(int x,int n) {
    int ans = 1;
    int base = x%mod;
    while (n>0) {
        if (n%2==1) {
            ans = mmul(ans, base);
        }
        n>>=1;
        base = mmul(base,base);
    }
    return ans;
}

void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<int>>arr(n,vector<int>(4));
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    vector<int>dp(m+1,0);
    int allnum = 1,alldenom=1;
    for(int i=0;i<n;i++) {
        allnum=mmul(allnum,arr[i][3]-arr[i][2]);
        alldenom=mmul(alldenom,arr[i][3]);
    }
    int proballnotexisting = mmul(allnum,mpow(alldenom,mod-2));
    sort(arr.begin(), arr.end(),[&](const auto &a, const auto &b){return a[1]<b[1];});
    for(int i=0;i<n;i++) {
        int l = arr[i][0];
        int r = arr[i][1];
        if (l==1) {
            int tmp=mmul(proballnotexisting,mpow(arr[i][3]-arr[i][2],mod-2));
            tmp=mmul(tmp,arr[i][2]);
            dp[r]=madd(dp[r],tmp);
        } else if (dp[l-1]!=0) {
            int tmp=mmul(dp[l-1],mpow(arr[i][3]-arr[i][2],mod-2));
            tmp=mmul(tmp,arr[i][2]);
            dp[r]=madd(dp[r],tmp);
        }
    }
    cout << dp[m] << "\n";
}


int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
