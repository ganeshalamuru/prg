#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

ll totalways(ll toplace, ll places) {
    ll total=1;
    while (toplace > 0)
    {
        ll numerator = 1,denomiantor = 1;
        for(int i=0;i<toplace;i++)
            numerator*=(places - i)*9;
        for(int i=1;i<=toplace;i++)
            denomiantor*=i;
        total += (numerator / denomiantor);
        toplace--;
    }
    return total;
}


ll numOfClassy(ll x) {
    string num = to_string(x);
    int nzds = 0;
    for(int i=0;i<num.size();i++) {
        if (num[i]!='0')
            nzds++;
        if(nzds > 3)
            num[i]='0';
    }
    ll total = 0, placed = 0;
    for(int i=0;i<num.size();i++) {
        if (num[i]=='0')
            continue;
        int digits = num.size()-i-1;
        // cur digit zero classy numbers
        total += totalways(3-placed, digits);
        // cur digit non zero classy numbers
        total += (num[i]-'0'-1)*(totalways(3-placed-1,digits));
        placed++;
    }
    return total;
}


void solve(){
	ll l,r;
    cin >> l >> r;
    l--;
    cout << numOfClassy(r) - numOfClassy(l) << "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
