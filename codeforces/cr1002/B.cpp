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




void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &num:a)
        cin >> num;
    map<int,int> freq;
    for(int i=1;i<n-k+2;i++) {
        freq[a[i]]++;
    }
    if (freq[1] != n-k+1) {
        cout << 1 << "\n";
        return;
    } else if (freq[1]>1) {
        cout << 2 << "\n";
        return;
    }
    int num=1;
    for(int i=1;i<n;i+=2,num++) {
        if (a[i]!=num) {
            cout << num << "\n";
            return;
        }
    }
    cout << num << "\n";
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
