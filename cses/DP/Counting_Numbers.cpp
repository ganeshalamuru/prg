#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


ll nums(ll c, vector<vector<ll>>&dp) {
    if (c<0)
        return 0;
    string s = to_string(c);
    int n = s.size();
    if (n==1)
        return c+1;
    ll ans = 1;
    for(int j=1;j<n-1;j++)
        ans+=dp[j+1][0];
    int pdigit = -1;
    for(int i=0;i<n;i++) {
        int digit = s[i]-'0';
        for(int d=0;d<digit;d++) {
            if (d==pdigit) continue;
            ans+=dp[n-i][d];
        }
        if (i==n-1 && digit!=pdigit)
            ans++;
        if (digit==pdigit)
            break;
        pdigit=digit;
    }
    return ans;

}

void solve() {
	ll a,b;
    cin >> a >> b;
    int n = to_string(b).size();
    vector<vector<ll>> dp(n+1,vector<ll>(10,0));
    for(int i=0;i<10;i++)
        dp[1][i]=1;
    for(int j=2;j<n+1;j++) {
        for(int d=0;d<10;d++) {
            for(int z=0;z<10;z++) {
                if (z==d) continue;
                dp[j][d] += dp[j-1][z];
            }
        }
    }
    ll t1 = nums(b,dp);
    ll t2 = nums(a-1,dp);
    cout << t1-t2 << "\n";

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
