#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;


int mod;
int madd(int a, int b) {
    return (((a+b)%mod)+mod)%mod;
}

void solve() {
	int n;
    cin >> n;
    mod = n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    vector<int> psum(n,0);
    psum[0]=madd(0, a[0]);
    for(int i=1;i<n;i++)
        psum[i]=madd(psum[i-1], a[i]);
    map<int,int> mp;
    mp[0]=1;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        ans+=mp[psum[i]];
        mp[psum[i]]++;
    }
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
