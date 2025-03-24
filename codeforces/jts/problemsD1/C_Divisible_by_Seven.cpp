#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}



int madd(ll a, ll b) {
    a%=mod, b%=mod;
    return (a+b)%mod;
}
int mmul(ll a, ll b) {
    a%=mod, b%=mod;
    return(a*b)%mod;
}

void solve() {
	string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(10,0);
    for(int i=0;i<n;i++)
        freq[s[i]-'0']++;
    map<int,string> mp{{0,"1869"},{1, "1896"},{2,"1986"},{3,"1698"},{4,"6198"},{5,"1689"},{6,"6189"}};
    if (freq[0]==n-4) {
        cout << mp[0] << string(n-4,'0') << "\n";
        return;
    }
    freq[1]--,freq[8]--,freq[6]--,freq[9]--;
    int rem = 0,powt=n-1;
    string ans="";
    vector<int> remms{1,3,2,-1,-3,-2};
    for(int j=9;j>=0;j--) {
        for(int i=0;i<freq[j];i++) {
            rem=madd(rem, mmul(j, remms[powt%6]+7));
            powt--;
            ans.push_back('0'+j);
        }
    }
    for(auto &ch:mp[rem])
        ans.push_back(ch);
    cout << ans << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
