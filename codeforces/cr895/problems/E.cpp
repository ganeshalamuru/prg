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


void solve(){
    int n;
    cin >> n;
    vector<int>arr(n),prefix(n+1,0);
    for(int &i:arr)
        cin >> i;
    string s;
    cin >> s;
    int ans0=0,ans1=0;
    for(int i=0;i<n;i++) {
        if (s[i]=='0')
            ans0^=arr[i];
        else
            ans1^=arr[i];
        prefix[i+1] = prefix[i]^arr[i];
    }
    int q;
    cin >> q;
    while(q--) {
        int tp;
        cin >> tp;
        if (tp==1) {
            int l,r;
            cin >> l >> r;
            ans0^=prefix[r]^prefix[l-1];
            ans1^=prefix[r]^prefix[l-1];
        } else {
            int zo;
            cin >> zo;
            cout << (zo ? ans1 : ans0) << " ";
        }
    }
    cout <<"\n";
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
