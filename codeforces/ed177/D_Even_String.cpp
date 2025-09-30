#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 998244353;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}



vector<int> fact(5e5l+1,0),invfact(5e5l+1,0);
void solve() {
	vector<int>arr(26,0);
    int tot = 0;
    for(int i=0;i<26;i++)
        cin >> arr[i],tot+=arr[i];
    if (tot==0) {
        cout << 0 << "\n";
        return;
    } else if (tot==1) {
        cout << 1 << "\n";
        return;
    }
    vector<int>dp(tot+1,0);
    dp[0]=1;
    for(int i=0;i<26;i++) {
        if (arr[i]==0)
            continue;
        for(int j=tot;j>=arr[i];j--)
            dp[j]=(dp[j]+dp[j-arr[i]]);
    }
    int numways = dp[tot/2];
    // if (tot%2==0)
    //     numways=(1ll*numways*invfact[2])%mod;
    int ans=(1ll*(fact[tot/2])*(fact[tot/2 + tot%2]))%mod;
    for(int i=0;i<26;i++) {
        if (arr[i]==0) continue;
        ans=(1ll*ans*invfact[arr[i]])%mod;
    }
    cout << (1ll*ans*numways)%mod << "\n";
}


int main() {
    fast;
    int t = 1;
    cin >> t;
    fact[0]=1;
    for(int i=1;i<5e5l+1;i++) {
        fact[i]=(1ll*i*fact[i-1])%mod;
    }
    for(int i=1;i<5e5l+1;i++) {
        invfact[i]=powe(fact[i],mod-2);
    }
    while(t--){
    	solve();
    }
    return 0;
}
