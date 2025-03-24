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
	int n,k,p;
    cin >> n >> k >> p;
    vector<vector<int>>a(2);
    for(int i=0,x;i<n;i++) {
        cin >> x;
        a[x%2].push_back(x);
    }
    int numodd = k-p;
    if (a[1].size() < numodd || (a[1].size() - numodd)%2==1) {
        cout << "NO\n";
        return;
    }
    if ((a[0].size() + (a[1].size()-numodd)/2) < p) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> ans(k);
    int i=0;
    i=p;
    while(i<k) {
        ans[i].push_back(a[1].back());
        a[1].pop_back();
        i++;
    }
    if (p>0) {
        i=0;
        while(!a[0].empty()) {
            ans[i].push_back(a[0].back());
            a[0].pop_back();
            i=(i+1)%p;
        }
        while (!a[1].empty()) {
            ans[i].push_back(a[1].back());
            a[1].pop_back();
            ans[i].push_back(a[1].back());
            a[1].pop_back();
            i=(i+1)%p;
        }
    } else {
        while (!a[0].empty()) {
            ans[p].push_back(a[0].back());
            a[0].pop_back();
        }
        while (!a[1].empty()) {
            ans[p].push_back(a[1].back());
            a[1].pop_back();
        }
    }
    cout << "YES\n";
    for(int j=0;j<k;j++) {
        cout << ans[j].size() << " " ;
        for(int &num:ans[j])
            cout << num << " ";
        cout << "\n";
    }
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
